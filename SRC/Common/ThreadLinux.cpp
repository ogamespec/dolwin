#include "pch.h"

Thread::Thread(ThreadProc threadProc, bool suspended, void* context, const char* name)
{
	running = !suspended;
	threadName = name;

	//ctx.context = context;
	//ctx.proc = threadProc;
	//threadHandle = CreateThread(NULL, StackSize, RingleaderThreadProc, &ctx, suspended ? CREATE_SUSPENDED : 0, &threadId);
	//assert(threadHandle != INVALID_HANDLE_VALUE);
}

Thread::~Thread()
{
	Suspend();

	//TerminateThread(threadHandle, 0);
	//WaitForSingleObject(threadHandle, 1000);
}

void Thread::Resume()
{
	resumeLock.Lock();
	if (!running)
	{
		//ResumeThread(threadHandle);
		running = true;
		resumeCounter++;
	}
	resumeLock.Unlock();
}

void Thread::Suspend()
{
	if (running)
	{
		running = false;
		suspendCounter++;
		//SuspendThread(threadHandle);
	}
}
