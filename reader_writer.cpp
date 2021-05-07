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
	InitializeCriticalSection(&RW_mutex); //初始化临界区
	InitializeCriticalSection(&SD_mutex); //初始化临界区
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
		}
		else
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
	EnterCriticalSection(&SD_mutex);
	WaitForSingleObject(W_mutex, -1);
	write_count++;
	ReleaseMutex(W_mutex);
	cout << "Writer thread " << m_id << " sends the writing require ! " << endl;
	LeaveCriticalSection(&SD_mutex);
	while(true)
	{
		if(read_count == 0)
		{
			//等待资源
			EnterCriticalSection(&RW_mutex);
			//执行写操作
			cout << "Writer thread " << m_id << " begins to write file ! " << endl;
			sleep(m_persist);
			cout << "Writer thread " << m_id << " finished writing file ! " << endl;
			//释放资源
			WaitForSingleObject(W_mutex, -1);
			write_count--;
			ReleaseMutex(W_mutex);
			LeaveCriticalSection(&RW_mutex);
			break;
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
	EnterCriticalSection(&SD_mutex);
	cout << "Reader thread " << m_id << " sends the reading require ! " << endl;
	LeaveCriticalSection(&SD_mutex);
	while (true)
	{
		if (write_count == 0)
		{
			EnterCriticalSection(&RW_mutex);
			read_count++;
			cout << "Reader thread " << m_id << " begins to read file ! " << endl;
			LeaveCriticalSection(&RW_mutex);
			sleep(m_persist);
			EnterCriticalSection(&RW_mutex);
			cout << "Reader thread " << m_id << " finished reading file ! " << endl;
			read_count--;
			LeaveCriticalSection(&RW_mutex);
			break;
		}
	}
}