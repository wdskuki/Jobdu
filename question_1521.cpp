#include <stdio.h>
#include <stdlib.h>
struct Node{
	Node *left, *right;
	int val;
};

int n;

void mirror(Node* node){
	if(node == NULL) return;
	
	Node* t = node->left;
	node->left = node->right;
	node->right = t;

	mirror(node->left);
	mirror(node->right);
}

void preTraversal(Node* node){
	if(node == NULL) return;
	//cout<<node->val<<" ";
	printf("%d ", node->val);
	preTraversal(node->left);
	preTraversal(node->right);
}

void init(){
	while(scanf("%d", &n) != EOF){
		if(n == 0){
			printf("NULL\n");
			continue;
		}
		//Node *node = new Node[n+1];
		Node *node = (Node *)malloc(sizeof(Node)*(n+1));
		for(int i = 1; i <= n; i++)
			scanf("%d", &(node[i].val));

		char c;
		int v1, v2;
		for(int i = 1; i <= n; i++){
			getchar();
			scanf("%c", &c);

			switch(c){
				case 'd': 
					scanf("%d%d", &v1, &v2);
					node[i].left = &node[v1];
					node[i].right = &node[v2];
					break;
				case 'l':
					scanf("%d", &v1);
					node[i].left = &node[v1];
					node[i].right = NULL;
					break;
				case 'r':
					scanf("%d", &v2);
					node[i].left = NULL;
					node[i].right = &node[v2];
					break;
				case 'z':
					node[i].left = NULL;
					node[i].right = NULL;
					break;
			}
		}
	//	preTraversal(&node[1]);printf("\n");
		mirror(&node[1]);
		preTraversal(&node[1]);printf("\n");
		
		free(node);
	}
	//printf("NULL\n");
}

int main(int argc, char const *argv[])
{
	init();
	return 0;
}