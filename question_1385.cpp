#include <iostream>
using namespace std;

struct Node{
	int val;
	Node *left, *right;
};

int n;
int *pre;
int *mid;
bool flag;

int findIndex(int *a, int b, int e, int val){
	for(int i = b; i <= e; i++){
		if(a[i] == val)
			return i;
	}
	return -1;
}

Node* reBuild(int b1, int e1,
			  int b2, int e2){

	if(b1 > e1 || b2 > e2)
		return NULL;

	int val = pre[b1];
	Node *node = new Node;
	node->val = val;
	int m2 = findIndex(mid, b2, e2, val);
	if(m2 == -1){
		//cout<<"error find: "<<val<<endl;
		flag = false;
		return NULL;
	}
	int m1 = m2-b2+b1;

	node->left = reBuild(b1+1, m1, b2, m2-1);
	node->right = reBuild(m1+1, e1, m2+1, e2);
	return node;
}

void posTraversal(Node *node){
	if(node == NULL)
		return;
	posTraversal(node->left);
	posTraversal(node->right);
	cout<<node->val<<" ";
}

void clean(Node *node){
	if(node == NULL)
		return;
	
	clean(node->left);
	clean(node->right);
	delete node;
}

int main(int argc, char const *argv[])
{
	while(cin>>n){
		pre = new int[n];
		mid = new int[n];
		flag = true;
		for(int i = 0; i < n; i++)
			cin>>pre[i];
		for(int i = 0; i < n; i++)
			cin>>mid[i];

		Node *root = reBuild(0, n-1, 0, n-1);
		if(flag){
			posTraversal(root);
			cout<<endl;
		}else
			cout<<"No"<<endl;
		clean(root);
		delete []pre;
		delete []mid;
	}
	return 0;
}