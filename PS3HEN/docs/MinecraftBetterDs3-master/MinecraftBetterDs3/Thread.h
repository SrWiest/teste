#include <PS3.h>
#pragma once
namespace Thread
{
	sys_ppu_thread_t id;
	sys_ppu_thread_t Create(void(*entry)(uint64_t), int priority, size_t stacksize, const char* threadname)
	{
		if (sys_ppu_thread_create(&id, entry, 0, priority, stacksize, 0, threadname) != CELL_OK)
		{
			console_write("Thread creation failed\n");
			Notify("Thread creation failed");
		}
		else
		{
			console_write("Thread created\n");
			Notify("Thread created");
		}
		return id;
	}
}
