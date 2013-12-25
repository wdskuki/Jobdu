#include <stdio.h>

bool flag = true;

void print(int a){
	if(flag){
		flag = false;
		printf("%d", a);
	}
	else{
		printf(" %d", a);
	}
}
int main(int argc, char const *argv[])
{
	int m, n;
	while(scanf("%d%d", &m, &n) != EOF){
		int **a;
		a = new int *[m];
		for(int i = 0; i < m; i++)
			a[i] = new int [n];

		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				scanf("%d",&a[i][j]);

		int left = 0;
		int right = n-1;
		int up = 0;
		int down = m-1;
		while(left <= right || up <= down){
			
			for(int j = left; j <= right; j++)
				print(a[up][j]);
			up++;

			for(int i = up; i <= down; i++)
				print(a[i][right]);
			right--;

			for(int j = right; j >= left; j--)
				print(a[down][j]);
			down--;

			for(int i = down; i >= up; i--)
				print(a[i][left]);
			left++;
		}
		printf("\n");
		for(int i = 0; i < m; i++)
			delete []a[i];
		delete []a;
	}
	return 0;
}