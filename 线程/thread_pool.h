#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <condition_variable>
#include <queue>
#include <vector>
#include <functional>

class ThreadPool
{
	ThreadPool(int numThreads): stop(false)
	{
		for (int i = 0; i < numThreads; i++)
		{
			threads.emplace_back([this]
			{
				while (1)
				{
					std::unique_lock<std::mutex> lock(mtx);
					condition.wait(lock, [this]
					{
						return !tasks.empty() || stop;
					});
					if (stop && tasks.empty())
					{
						return;
					} //if

					std::function<void()> task(std::move(tasks.front()));
					tasks.pop();
					lock.unlock();
				} //while
			});
		} //for
	}

private:
	std::vector<std::thread> threads;
	std::queue<std::function<void()>> tasks;

	std::mutex mtx;
	std::condition_variable condition;

	bool stop;
};
