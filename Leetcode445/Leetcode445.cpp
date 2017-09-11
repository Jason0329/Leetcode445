// Leetcode445.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>       // std::cout
#include <stack>          // std::stack
#include <vector>         // std::vector
#include <deque>          // std::deque

using namespace std;
int main()
{
    return 0;
}

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		stack<int> s1, s2; // store digits in stack
		for (; l1; l1 = l1->next) s1.push(l1->val);
		for (; l2; l2 = l2->next) s2.push(l2->val);

		ListNode *res = new ListNode(0), *tmp = NULL;
		for (int sum = 0; !s1.empty() || !s2.empty(); tmp = new ListNode(sum /= 10), tmp->next = res, res = tmp) {
			if (!s1.empty()) sum += s1.top(), s1.pop(); // get digit sum
			if (!s2.empty()) sum += s2.top(), s2.pop();
			res->val = sum % 10;
		}
		return res->val ? res : res->next;




	}
};

