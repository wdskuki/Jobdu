#include <iostream>
#include <stdio.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
};

ListNode* reverseList_nonRecursive(ListNode *head){
	if(head == NULL || head->next == NULL)
		return head;

	ListNode *newhead = head;
	ListNode *temp;
	head = head->next;
	newhead->next = NULL;

	while(head != NULL){
		temp = head->next;
		head->next = newhead;
		newhead = head;
		head = temp;
	}
	return newhead;
}


/* [Reference] 
 * 	http://ceeji.net/blog/reserve-linked-list-cpp/#递归解法一
 */
ListNode* reverseList_recursive(ListNode *head){
	if(head == NULL || head->next == NULL)
		return head;
	ListNode *ptrHeadNext = reverseList_recursive(head->next);
	//ListNode *temp = ptrHeadNext->next;
	head->next = NULL;
	ptrHeadNext->next = head;
	return head;
}


ListNode* reverseList_recursive_2(ListNode *oldhead, ListNode *newhead){
	if(oldhead == NULL)
		return newhead;
	ListNode *tempNode = oldhead;
	oldhead = oldhead->next;
	tempNode->next = newhead;
	newhead = tempNode;
	return reverseList_recursive_2(oldhead, newhead); 
}

void print(ListNode *head){
	while(head != NULL){
		if(head->next != NULL)
			cout<<head->val<<" ";
		else
			cout<<head->val<<endl;
		head = head->next;
	}
}

void clear(ListNode *head){
	if(head == NULL)
		return;
	ListNode *temp = head->next;
	delete head;
	clear(temp);
}

void test(){
	int a[] = {1,2,3,4,5};
	int len = 5;

	ListNode node[5];
	for(int i = 0; i < len-1; i++){
		node[i].val = a[i];
		node[i].next = &node[i+1];
	}
	node[len-1].val = a[len-1];
	node[len-1].next = NULL;

	print(&node[0]);
	ListNode* newNode = reverseList_nonRecursive(&node[0]);
	print(newNode);
}
int main(int argc, char const *argv[])
{
	int n;
	ListNode *node;
	while(scanf("%d", &n) != EOF){
		if(n == 0){
			cout<<"NULL"<<endl;
			continue;
			//break;
		}
		node = new ListNode [n];
		for(int i = 0; i < n; i++){
			cin>>node[i].val;
		}
		for(int i = 0; i < n; i++){
			if(i == n-1)
				node[i].next = NULL;
			else
				node[i].next = &node[i+1];
		}
		//ListNode *newhead = reverseList_nonRecursive(&node[0]);
		//reverseList_recursive(&node[0]);
		//print(&node[n-1]);

		//ListNode *newhead = reverseList_nonRecursive(&node[0]);
		
		ListNode *newhead = reverseList_recursive_2(&node[0], NULL);

		print(newhead);

		delete [] node;
	}
	return 0;
}