#include <deque>
#include <iostream>
using namespace std;

void print(deque<int> &dq){
	int size = dq.size();
	for(int i = 0; i < size-1; i++)
		cout<<dq.at(i)<<" ";
	cout<<dq.at(size-1)<<endl;
}
void findContinueSeq(int s){
	if(s == 0 || s == 1 || s == 2){
		cout<<"Pity!"<<endl;
		cout<<"#"<<endl;
		return;
	}

	deque<int> dq;
	int sum = 0;
	bool flag = false;
	int i = 1;
	while(i < s){
		if(sum == s){
			flag = true;
			print(dq);
			sum -= dq.front();
			dq.pop_front();
			i++;
		}else if(sum < s){
			while(sum < s){
				dq.push_back(i);
				sum += i;
				i++;
			}
	//		i--;
		}else{
			while(sum > s && ( !dq.empty() )){
				sum -= dq.front();
				dq.pop_front();
			}
		}
	}
	if(!flag)
		cout<<"Pity!"<<endl;
	
	cout<<"#"<<endl;
}



int main(int argc, char const *argv[])
{
	int s;
	while(cin>>s){
		if(s <= -1) continue;
		findContinueSeq(s);
	}
	return 0;
}