#include <math.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", &n) != EOF){
		for(int i = 0; i < n; i++){
			float base;
			int exponent;
			scanf("%f %d", &base, &exponent);
			double t = pow(base,exponent);
			if(t == pow(0.0, -5))
				printf("INF\n");
			else
				printf("%.2ef\n", t);
		}
	}
	return 0;
}