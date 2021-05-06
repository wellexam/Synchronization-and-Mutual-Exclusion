#include <Windows.h>
#include <fstream>
#include <iostream>
#include<string>

using namespace std;

#define sleep(n) Sleep((n) * 1000)

class Thread_info
{
public:
    int tid;        //线程ID
    char role;      //扮演角色 R or W
    double delay;   //线程延迟
    double persist; //线程读写操作持续时间
};

void WriterThread(Thread_info &t);

void ReaderThread(Thread_info &t);

int Read_count = 0;
HANDLE Rmutex;             //RW_mutex;//局部临界资源
CRITICAL_SECTION RW_mutex; //全局临界资源

int main()
{
    DWORD n_thread = 0; //线程数目
    DWORD thread_ID;    //线程ID
    //线程对象数组
    HANDLE h_thread[20];
    Thread_info thread_info[20];
    //初始化同步对象
    Rmutex = CreateMutex(nullptr, FALSE, "mutex_for_readcount");
    InitializeCriticalSection(&RW_mutex); //初始化临界区
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
    DWORD wait_for_all = WaitForMultipleObjects(n_thread, h_thread, true, -1);
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
    cout << "Writer thread " << m_id << " snets the writing require ! " << endl;
    //等待资源
    EnterCriticalSection(&RW_mutex);//DWORD waits = WaitForSingleObject(RW_mutex, -1);
    //执行写操作
    cout << "Writer thread " << m_id << " begins to write file ! " << endl;
    sleep(m_persist);
    cout << "Writer thread " << m_id << " finished writing file ! " << endl;
    //释放资源
    LeaveCriticalSection(&RW_mutex);//RealeaseMutex(RW_mutex);
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
    cout << "Reader thread " << m_id << " snets the reading require ! " << endl;
    //等待互斥信号量，保证对readcount的互斥访问
    DWORD wait_for_mutex = WaitForSingleObject(Rmutex, -1);
    if (Read_count == 0)
    {
        EnterCriticalSection(&RW_mutex);//DWORD waits = WaitForSingleObject(RW_mutex, -1);
    }
    Read_count++;
    ReleaseMutex(Rmutex);
    //执行读操作
    cout << "Reader thread " << m_id << " begins to read file ! " << endl;
    sleep(m_persist);
    cout << "Reader thread " << m_id << " finished reading file ! " << endl;
    //释放互斥信号量
    wait_for_mutex = WaitForSingleObject(Rmutex, -1);
    Read_count--;
    if (Read_count == 0)
    {
        LeaveCriticalSection(&RW_mutex);//RealeaseMutex(RW_mutex);
    }
    ReleaseMutex(Rmutex);
}