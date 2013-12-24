#include <iostream>
#include <algorithm>
using namespace std;

int L, M;
struct Range{
	int x, y;
};

bool myCompareFunc(Range a1, Range a2){
	return a1.x < a2.x;
}

int main(int argc, char const *argv[])
{

	while(cin>>L>>M){
		if(M == 0){
			cout<<L<<endl;
			continue;
		}
		
		Range *a = new Range[M];
		
		for(int i  = 0; i < M; i++)
			cin>>a[i].x>>a[i].y;

		sort(a, a+M, myCompareFunc);

		int beg = a[0].x;
		int end = a[0].y;
		int remain = (L+1) - (end - beg + 1);
		for(int i = 1; i < M; i++){
			if(a[i].x > end){
				beg = a[i].x;
				end = a[i].y;
				remain = remain - (end - beg + 1);
			}else if(a[i].y > end){
				remain = remain - (a[i].y - end);
				end = a[i].y;
			}
		}

		cout<<remain<<endl;

		delete []a;
	}
	return 0;
}