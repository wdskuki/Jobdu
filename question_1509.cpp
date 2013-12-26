//reference:
//http://blog.csdn.net/zhu_liangwei/article/details/12403071

#include <iostream>
#include <stack>
#include <fstream>
using namespace std;


struct Node{
	int val;
	Node *left, *right;
	int count;
};



Node *buildTree(ifstream& infile){
	int val;
	infile>>val;
	if(val == 0)
		return NULL;
	Node *node = new Node;
	node->val = val;
	node->count = 0;
	node->left = buildTree(infile);
	node->right = buildTree(infile);
	return node;
}

bool findPath(Node *root, int val, stack<Node *>& s){
	if(root == NULL)
		return false;

	root->count++;
	s.push(root);
	if(root->val == val)
		return true;
	else{
		bool b1 = findPath(root->left, val, s);
		bool b2 = findPath(root->right, val, s);
		if(b1 == false && b2 == false){
			Node* n = s.top();
			n->count--;
			s.pop();
		}
		return (b1||b2);
	}
}

void clear(Node *root){
	if(root == NULL)
		return;
	clear(root->left);
	clear(root->right);
	delete root;
}
int main(int argc, char const *argv[])
{
	int n;
	ifstream infile("input.in");
	while(infile>>n){
		Node *root = buildTree(infile);
		int a, b;
		infile>>a>>b;
		stack<Node* > s1, s2;
		if((findPath(root, a, s1)&&findPath(root, b, s2)) == false)
			cout<<"My God\n"<<endl;
		else{
			while(!s1.empty()){
				Node *n = s1.top();
				s1.pop();
				if(n->count == 2){
					cout<<n->val<<endl;
					break;
				}
			}
		}

	}
	infile.close();
	return 0;
}