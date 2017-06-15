#include "stdafx.h"
#include "CppUnitTest.h"
#include <assert.h>
#include "MyQueue.h"
#include <assert.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		

		TEST_METHOD(TestEnqueue)
		{
			MyQueue testQueue;
			vector<int> test;
			Assert::IsTrue(testQueue.getQueue() == test, L"E1", LINE_INFO());

			testQueue.enqueue(5);
			test.push_back(5);
			Assert::IsTrue(testQueue.getQueue() == test, L"E2", LINE_INFO());

			testQueue.enqueue(6);
			testQueue.enqueue(8);
			test.push_back(6);
			test.push_back(8);
			Assert::IsTrue(testQueue.getQueue() == test, L"E3", LINE_INFO());
		}		

		
		TEST_METHOD(TestDequeue)
		{
			MyQueue testQueue;
			testQueue.enqueue(5);
			testQueue.enqueue(6);
			testQueue.enqueue(7);
			vector<int> test;
			test.push_back(6);
			test.push_back(7);

			Assert::AreEqual(testQueue.dequeue(), 5);
			//Assert::IsTrue(testQueue.getQueue() == test, L"D1", LINE_INFO());
			test.erase(test.begin());
			Assert::AreEqual(testQueue.dequeue(), 6);
			//Assert::IsTrue(testQueue.getQueue() == test, L"D2", LINE_INFO());
			test.erase(test.begin());
			Assert::AreEqual(testQueue.dequeue(), 7);
			//Assert::IsTrue(testQueue.getQueue() == test, L"D3", LINE_INFO());
		}

		TEST_METHOD(TestMax)
		{
			MyQueue testQueue;

			testQueue.enqueue(5);
			int max = 5; // 5
			Assert::IsTrue(testQueue.maximum() == max, L"MA1", LINE_INFO());

			testQueue.enqueue(3);
			Assert::IsTrue(testQueue.maximum() == max, L"MA2", LINE_INFO()); // 5 3

			testQueue.enqueue(8);
			max = 8;
			Assert::IsTrue(testQueue.maximum() == max, L"MA3", LINE_INFO()); // 5 3 8

			testQueue.enqueue(4);
			testQueue.dequeue();
			Assert::IsTrue(testQueue.maximum() == max, L"MA4", LINE_INFO()); // 3 8 4

			testQueue.dequeue();
			testQueue.dequeue();
			max = 4;
			Assert::IsTrue(testQueue.maximum() == max, L"MA5", LINE_INFO()); // 4
		}

		TEST_METHOD(TestMin)
		{
			MyQueue testQueue;

			testQueue.enqueue(5);
			int min = 5;
			Assert::IsTrue(testQueue.minimum() == min, L"MI1", LINE_INFO());// 5

			testQueue.enqueue(3);
			min = 3;
			Assert::IsTrue(testQueue.minimum() == min, L"MI2", LINE_INFO()); // 5 3

			testQueue.enqueue(8);
			Assert::IsTrue(testQueue.minimum() == min, L"MI3", LINE_INFO());// 5 3 8

			testQueue.enqueue(7);
			testQueue.dequeue();
			Assert::IsTrue(testQueue.minimum() == min, L"MI4", LINE_INFO()); // 3 8 7

			testQueue.dequeue();
			testQueue.dequeue();
			min = 7;
			Assert::IsTrue(testQueue.minimum() == min, L"MI5", LINE_INFO()); // 7
		}

	};
}