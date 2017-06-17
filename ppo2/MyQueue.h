#include <vector>
#include <stack>
#pragma once
#define MAX_ELEMENTS 5
using namespace std;

class MyQueue
{
public:
	MyQueue();
	~MyQueue();

	virtual void enqueue(int value);
	virtual int dequeue();
	virtual int minimum();
	virtual int maximum();

	virtual vector<int> getQueue();

protected:
	struct Element {
		Element() :
			max(0),
			min(0),
			value(0)
		{
		}

		Element(int m_min, int m_max, int m_val) :
			max(m_max),
			min(m_min),
			value(m_val)
		{
		}

		int max;
		int min;
		int value;
	};

	void stackPush(stack<Element> &stack, int value);
	stack<Element> inStack;
	stack<Element> outStack;
};



