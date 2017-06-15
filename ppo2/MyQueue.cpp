#include "stdafx.h"
#include "MyQueue.h"
#include <assert.h>

using namespace std;

MyQueue::MyQueue() {

}
MyQueue::~MyQueue() {

}

void MyQueue::enqueue(int value)
{
	if (inStack.size() + outStack.size() == MAX_ELEMENTS)
		dequeue();

	stackPush(inStack, value);
}

int MyQueue::dequeue()
{
	assert(inStack.size() + outStack.size() != 0);

	if (outStack.size() > 0) {
		int t = outStack.top().value;
		outStack.pop();
		return t;
	}
	else {
		while (!inStack.empty()) {
			int t = inStack.top().value;
			inStack.pop();
			stackPush(outStack, t);
		}
		int t = outStack.top().value;
		outStack.pop();
		return t;
	}
}

int MyQueue::minimum()
{
	return 0;
}

int MyQueue::maximum()
{
	return 0;
}

vector<int> MyQueue::getQueue()
{
	return vector<int>();
}

void MyQueue::stackPush(stack<Element>& stack, int value)
{
	Element newElement(value, value, value);

	if (stack.size() > 0) {
		if (stack.top().max < value)
			newElement.max = value;
		else
			newElement.max = stack.top().max;

		if (stack.top().min > value)
			newElement.min = value;
		else
			newElement.min = stack.top().min;
	}

	stack.push(newElement);
}

