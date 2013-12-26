#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d", &n) != EOF){
		switch(n){
			case 1:
				for(int i = 1; i <= 9; i++)
					printf("%d\n", i);
				break;
			case 2:
				for(int i = 1; i <= 99; i++)
					printf("%d\n", i);
				break;
			case 3:
				for(int i = 1; i <= 999; i++)
					printf("%d\n", i);
				break;
			case 4:
				for(int i = 1; i <= 9999; i++)
					printf("%d\n", i);
				break;
			case 5:
				for(int i = 1; i <= 99999; i++)
					printf("%d\n", i);
				break;				
		}	
	}
	return 0;
}