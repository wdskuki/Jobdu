#include <iostream>
using namespace std;
#include <stdio.h>
void permutation(int n, int m, int x, int &num){
	if(n == 1 && x <= m){
		num = num + 1;
		return;
	}
	for(int i = 1; i <= m; i++){
		if(i < x)
			permutation(n-1, m, x-i, num);
	}
}


void calculateProbability(int n, int m, int firstNum){
	float p = 1.0;
	for(int i = 0; i < n; i++)
		p *= (1.0/m);
	float res;
	if(n == 1){
		for(int i = 1; i <= firstNum; i++){
			printf("%d %.2f\n", i, p);
			//cout<<i<<" "<<a[i]<<endl;
		}
		return;
	}
	else{
		int t1 = m*n-n+1;
		int max1, max2, max3;
		int max1Num,max2Num, max3Num;
		max1Num = 0;
		max2Num = 0;
		max3Num = 0;
		float max1value = 0.0;
		float max2value = 0.0;
		float max3value = 0.0;
		max2 = n+t1/2;	permutation(n, m, max2, max2Num);
		max3 = max2+1; 	permutation(n, m, max3, max3Num);
		max1 = max2-1;	permutation(n, m, max1, max1Num);

		max1value = p*max1Num;
		max2value = p*max2Num;
		max3value = p*max3Num;


		printf("%d %.2f\n", max1, max1value);
		printf("%d %.2f\n", max2, max2value);
		printf("%d %.2f\n", max3, max3value);
		// if(t1%2 == 0){
		// 	max3 = max2+1;
		// 	max1 = max2-1;
		// }else{
		// 	max1 = max2-1;
		// 	max3 = max2+1; 
		// }
	}
}
void print(int *a, int num){
	for(int i = 1; i <= num; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	int n,m;
	while(cin>>n){
		if(n == 0) break;
		else cin>>m;

//		int *a = new int [n*m+1];
//		for(int i = 1; i <= n*m; i++)
//			a[i] = 0;
		
		calculateProbability(n, m, 3);
//		print(a, n*m);
//		delete []a;
	}
	return 0;
}