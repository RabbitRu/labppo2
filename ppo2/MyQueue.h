#include <vector>
#include <stack>
#pragma once
#include "Ique.h"
#define MAX_ELEMENTS 5
using namespace std;

class MyQueue : public Ique
{
public:
	MyQueue();
	~MyQueue();

	virtual void enqueue(int value);
	virtual int dequeue();
	virtual int minimum();
	virtual int maximum();

	virtual vector<int> getQueue();

};



