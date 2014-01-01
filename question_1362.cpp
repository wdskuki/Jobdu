#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	string str;
	int n;
	while(cin>>str>>n){
		int size = str.size();
		string newstr(str);
		n %= size;
		for(int i = 0; i < size; i++){
			if(i >= n){
				newstr[i-n] = str[i];
			}else{
				newstr[size+i-n] = str[i];
			}
		}
		cout<<newstr<<endl;
	}
	return 0;
}