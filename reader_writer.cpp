#include <Windows.h>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

#define sleep(n) Sleep((n) * 1000)

class Thread_info
{
public:
    int tid;        //线程ID
    char role;      //扮演角色 R or W
    DWORD delay;   //线程延迟
    DWORD persist; //线程读写操作持续时间
};

void WriterThread(Thread_info &t);

void ReaderThread(Thread_info &t);

int write_count = 0, read_count = 0;
HANDLE W_mutex;   //局部临界资源
CRITICAL_SECTION RW_mutex, SD_mutex; //全局临界资源

int main()
{
    DWORD n_thread = 0; //线程数目
    DWORD thread_ID;    //线程ID
    //线程对象数组
    HANDLE h_thread[20];
    Thread_info thread_info[20];
    //初始化同步对象
    InitializeCriticalSection(&RW_mutex); //初始化读写临界区
    InitializeCriticalSection(&SD_mutex); //初始化申请消息发送临界区
    //读取输入文件
    fstream file;
    file.open(R"(.\data_1.txt)", ios::in);
    if (!file)
    {
        cout << "error in open file ! " << endl;
        return -1;
    }
    while (file)
    {
        file >> thread_info[n_thread].tid;
        file >> thread_info[n_thread].role;
        file >> thread_info[n_thread].delay;
        file >> thread_info[n_thread].persist;
        n_thread++;
    }
    file.close();
    //创建线程
    for (int i = 0; i < n_thread; i++)
    {
        if (thread_info[i].role == 'R' || thread_info[i].role == 'r')
        {
            h_thread[i] = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE) (ReaderThread), &thread_info[i], 0,
                                       &thread_ID);
        } else
        {
            h_thread[i] = CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE) (WriterThread), &thread_info[i], 0,
                                       &thread_ID);
        }
    }
    //等待所有线程结束
    WaitForMultipleObjects(n_thread, h_thread, true, -1);
    cout << "All reader and writer have finished operating ! " << endl;
    return 0;
}

void WriterThread(Thread_info &t)
{
    DWORD m_delay;
    DWORD m_persist;
    int m_id;
    //从参数中获取信息
    m_delay = t.delay;
    m_persist = t.persist;
    m_id = t.tid;
    sleep(m_delay);//延迟等待
    //进入申请消息发送临界区
    EnterCriticalSection(&SD_mutex);
    WaitForSingleObject(W_mutex, -1);//申请占用维护写者等待计数器的互斥量
    write_count++;//写者等待计数器加一
    ReleaseMutex(W_mutex);//释放维护写者等待计数器的互斥量
    cout << "Writer thread " << m_id << " sends the writing require ! " << endl;
    LeaveCriticalSection(&SD_mutex);
    while (true)//忙等
    {
        if (read_count == 0)//当没有读者在读写临界区时，申请进入读写临界区
        {
            //等待资源
            EnterCriticalSection(&RW_mutex);//申请进入读写临界区
            //执行写操作
            cout << "Writer thread " << m_id << " begins to write file ! " << endl;
            sleep(m_persist);
            cout << "Writer thread " << m_id << " finished writing file ! " << endl;
            //释放资源
            WaitForSingleObject(W_mutex, -1);//申请占用维护写者等待计数器的互斥量
            write_count--;//写者等待计数器减一
            ReleaseMutex(W_mutex);//释放维护写者等待计数器的互斥量
            LeaveCriticalSection(&RW_mutex);//离开读写临界区
            break;//结束该线程
        }
    }
}

void ReaderThread(Thread_info &t)
{
    DWORD m_delay;
    DWORD m_persist;
    int m_id;
    //从参数中获取信息
    m_delay = t.delay;
    m_persist = t.persist;
    m_id = t.tid;
    sleep(m_delay);//延迟等待
    //进入申请消息发送临界区
    EnterCriticalSection(&SD_mutex);
    cout << "Reader thread " << m_id << " sends the reading require ! " << endl;
    LeaveCriticalSection(&SD_mutex);
    while (true)//忙等
    {
        if (write_count == 0)//当没有写者在等待时，申请进入读写临界区
        {
            EnterCriticalSection(&RW_mutex);//申请进入读写临界区
            read_count++;//读者计数器加一
            cout << "Reader thread " << m_id << " begins to read file ! " << endl;//开始读取
            LeaveCriticalSection(&RW_mutex);//离开读写临界区
            sleep(m_persist);
            EnterCriticalSection(&RW_mutex);//申请进入读写临界区
            cout << "Reader thread " << m_id << " finished reading file ! " << endl;//结束读取
            read_count--;//读者计数器减一
            LeaveCriticalSection(&RW_mutex);//离开读写临界区
            break;
        }
    }
}