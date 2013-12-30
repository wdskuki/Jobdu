#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class EightQueens{
public:
	vector<vector<int> > iivec;
	int n;
	int **chess;
	EightQueens(int i):n(i){}
	~EightQueens(){
		iivec.clear();
		for(int i = 0; i < n; i++)
			delete []chess[i];
		delete []chess;
	}
	void searchAllQueens(){
		chess = new int *[n];
		for(int i = 0; i < n; i++)
			chess[i] = new int [n];

		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				chess[i][j] = 0;

		vector<int> ivec;
		findQueensStr(0, ivec);
	}

	void findQueensStr(int row, vector<int> ivec){
		if(row == n){
			iivec.push_back(ivec);
	//		print_chess();
			return;
		}
		for(int i = 0; i < n; i++){
			if(isSafePos(row, i)){
				chess[row][i] = 1;
				ivec.push_back(i+1);
				findQueensStr(row+1, ivec);
				ivec.pop_back();
				chess[row][i] = 0;
			}
		}

	}

	bool isSafePos(int x, int y){
		for(int i = 0; i < n; i++){
			if(chess[x][i] == 1)
				return false;
		}

		for(int i = 0; i < n; i++){
			if(chess[i][y] == 1)
				return false;
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(abs(i-x) == abs(j-y)){
					if(chess[i][j] == 1)
						return false;
				}
			}
		}

		return true;
	}

	void print_chess(){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cout<<chess[i][j]<<" ";
			cout<<endl;
		}
		cout<<"\n\n";
	}
};

int main(int argc, char const *argv[])
{
	EightQueens eq(8);
	eq.searchAllQueens();

	// for(int i = 0; i < eq.iivec.size(); i++){
	// 	for(int j = 0; j < eq.n; j++)
	// 		cout<<(eq.iivec)[i][j];
	// 	cout<<endl;
	// }
	
	int N;
	while(cin>>N){
		int index;
		for(int i = 0; i < N; i++){
			cin>>index;
			for(int i = 0; i < eq.n; i++){
				cout<<(eq.iivec)[index-1][i];
			}
			cout<<endl;
		}
	}

	return 0;
}