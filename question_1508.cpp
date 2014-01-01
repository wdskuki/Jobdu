#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	string str;
	while(cin>>str){
		int size = str.size();
		int res = 0;
		bool flag = true;
		bool flag2 = true;
		for(int i = 0; i < size; i++){
			if(i == 0){
				if(str[i] == '-'){
					flag = false;
					continue;
				}else if(str[i] == '+'){
					continue;
				}else if(str[i] < '0' || str[i] > '9'){
					cout<<"My God"<<endl;
					flag2 = false;
					break;
				}else{
					res = res*10+(str[i]-'0');
				}
			}else{
				if(str[i] < '0' || str[i] > '9'){
					cout<<"My God"<<endl;
					flag2 = false;
					break;
				}else{
					res = res*10+(str[i]-'0');
				}
			}
		}
		if(!flag2)
			continue;
		if(flag)
			cout<<res<<endl;
		else
			cout<<res*(-1)<<endl;
	}
	return 0;
}