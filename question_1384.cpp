#include <iostream>
#include <stdio.h>
using namespace std;

class FindNum{
public:
	int m, n;
	int t;
	int **a;
	bool yn;

	bool findNum(int row, int col){
		if(row >= m || col < 0)
			return false;

		if(a[row][col] == t)
			return true;
		else if(a[row][col] > t)
			return findNum(row, col-1);
		else 
			return findNum(row+1, col);
	}

	
	void run(){
		while(scanf("%d%d%d", &m, &n, &t) != EOF){
			init();
			yn = findNum(0, n-1);
			print();
			clear();
		}
	}

	void init(){
		//cin>>m>>n;
		//cin>>t;
		a = new int*[m];
		for(int i = 0; i < m; i++)
			a[i] = new int [n];
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				scanf("%d", &a[i][j]);
		yn = false;
	}

	void print(){
		if(yn)
			printf("Yes\n");
			//cout<<"Yes"<<endl;
		else
			printf("No\n");
			//cout<<"No"<<endl;
	}

	void clear(){
		for(int i = 0; i < m; i++)
			delete []a[i];
		delete []a;
	}
};

int main(int argc, char const *argv[])
{
	FindNum fn;
	fn.run();
	return 0;
}