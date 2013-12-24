#include <iostream>
using namespace std;
struct Node{
	Node *left, *right;
	int val;
};
int n; 
int deep = -1;

void dfs(Node *node, int len){
	if(node == NULL)
		return;
	if(node->left == NULL && node->right == NULL){
		++len;
		deep = deep < len? len : deep;
		return;
	}
	dfs(node->left, len+1);
	dfs(node->right, len+1);
}



int main(int argc, char const *argv[])
{
	while(cin>>n){
		deep = -1;
		Node *node = new Node[n];
		int left, right;
		for(int i = 0; i < n; i++){
			cin>>left>>right;
			
			if(left == -1)
				node[i].left = NULL;
			else
				node[i].left = &node[left-1];

			if(right == -1)
				node[i].right = NULL;
			else
				node[i].right = &node[right-1];
		}

		dfs(&node[0], 0);

		cout<<deep<<endl;

		delete []node;
	}
	return 0;
}