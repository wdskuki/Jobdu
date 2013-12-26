#include <iostream>
#include <stdio.h>
using namespace std;
struct Pair{
	int x, y;
};

int xorSum(int *a, int beg, int end){
	int sumNum = 0;
	for(int i = beg; i <= end; i++)
		sumNum ^= a[i];
	return sumNum;
}

bool isBitOne(int x, int i){
	return (x>>i)&1 == 1? true : false;
}

Pair findSinglePair(int *a, int beg, int end){
	int t = xorSum(a, beg, end);

	int i = 0;
	int index = -1;
	while(1){
		if(isBitOne(t, i)){
			index = i;
			break;
		}
		i++;
	}

	int r1 = 0;
	int r2 = 0;
	for(int i = beg; i <= end; i++){
		if(isBitOne(a[i], index))
			r1 ^= a[i];
		else
			r2 ^= a[i];
	}

	Pair pair;
	pair.x = r1 > r2 ? r2 : r1;
	pair.y = r1 > r2 ? r1 : r2;
	return pair;
}
// Pair findSinglePair(int *a, int beg, int end){
// 	if(beg >= end){
// 		Pair pair;
// 		pair.x = -1;
// 		pair.y = -1;
// 		return pair;
// 	}
// 	int mid = (beg + end)/2;
// 	int leftSum = xorSum(a, beg, mid);
// 	int rightSum = xorSum(a, mid+1, end);
// 	if(leftSum != 0 && rightSum != 0){
// 		Pair pair;
// 		pair.x = leftSum < rightSum ? leftSum : rightSum;
// 		pair.y = leftSum < rightSum ? rightSum : leftSum;
// 		return pair;
// 	}
// 	else if(leftSum == 0)
// 		return findSinglePair(a, mid+1, end);
// 	else
// 		return findSinglePair(a, beg, mid);
// }

int main(int argc, char const *argv[])
{
	int n;
	int *a;
	while(cin>>n){
		a = new int[n];
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		Pair pair = findSinglePair(a, 0, n-1);
		cout<<pair.x<<" "<<pair.y<<endl;
		delete []a;
	}
	return 0;
}