// ppo2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Ique.h"
#include "MyQueue.h"

int main()
{
	Ique * qe = new MyQueue();
	vector<int> queue;
	rand();
	int code, output, min = 0, max = 10;
	printf("Input 0 to exit or any int to continue\n");
	scanf_s("%d", &code);
	while (code != 0) {
		output = min + (rand() % (max - min + 1));
		qe->enqueue(output);
		queue = ((MyQueue*)qe)->getQueue();
		printf("max:%d min:%d queue:", qe->maximum(), qe->minimum());
		for (int i = 0; i < queue.size(); i++)
			printf("%d ", queue[i]);
		printf("\n");
		scanf_s("%d", &code);
	}
	return 0;
}

