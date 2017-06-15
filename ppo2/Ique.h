#pragma once
#include <vector>

class Ique
{
public:
	virtual void enqueue(int value) = 0;
	virtual int dequeue() = 0;
	virtual int minimum() = 0;
	virtual int maximum() = 0;
	virtual std::vector<int> getQueue() = 0;
};

