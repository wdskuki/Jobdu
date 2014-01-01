#include <iostream>
#include <stdio.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
};

void printList(ListNode *head){
	if(head == NULL)
		return;
	while(head->next != NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<head->val<<endl;
}

ListNode* combineTwoList(ListNode* list1, ListNode* list2){
	ListNode *pos1 = list1;
	ListNode *pos2 = list2;
	ListNode *newhead, *newtail;
	newhead = newtail = NULL;

	while(pos1 != NULL || pos2 != NULL){
		if(pos1 == NULL){
			newtail->next = pos2;
			return newhead;
		}
		if(pos2 == NULL){
			newtail->next = pos1;
			return newhead;
		}

		if(pos1->val < pos2->val){
			if(newhead == NULL){
				newhead = pos1;
				newtail = pos1;
			}else{
				newtail->next = pos1;
				newtail = newtail->next;
			}
			pos1 = pos1->next;
		}else{
			if(newhead == NULL){
				newhead = pos2;
				newtail = pos2;
			}else{
				newtail->next = pos2;
				newtail = newtail->next;
			}
			pos2 = pos2->next;
		}
	}

}
int main(int argc, char const *argv[])
{
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF){
		if(n == 0 && m == 0){
			cout<<"NULL"<<endl;
			continue;
		}

		ListNode *list1 = new ListNode[n];
		ListNode *list2 = new ListNode[m];
		
		for(int i = 0; i < n; i++){
			cin>>list1[i].val;
			list1[i].next = NULL;
		}
		for(int i = 0; i < n-1; i++)
			list1[i].next = &list1[i+1];

		for(int i = 0; i < m; i++){
			cin>>list2[i].val;
			list2[i].next = NULL;
		}
		for(int i = 0; i < m-1; i++)
			list2[i].next = &list2[i+1];

		if(n == 0){
			printList(&list2[0]);
			delete []list1;
			delete []list2;
		}else if(m == 0){
			printList(&list1[0]);
			delete []list1;
			delete []list2;
		}else{
			ListNode *newhead = combineTwoList(&list1[0], &list2[0]);
			printList(newhead);

			delete []list1;
			delete []list2;
		}

	}
	return 0;
}