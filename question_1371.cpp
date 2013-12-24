#include <iostream>
using namespace std;

long n, k;
long *a;

void max_heapify(long *a, long i, long heap_size){
	long left = i*2;
	long right = i*2+1;
	long large = i;
	if(left <= heap_size && a[left] > a[i])
		large = left;
	if(right <= heap_size && a[right] > a[large])
		large = right;
	if(large != i){
		long t = a[i];
		a[i] = a[large];
		a[large] = t;
		max_heapify(a, large, heap_size);
	}
}

void build_max_heap(long *a, long len){
	long heap_size = len;
	for(long i = len/2; i >= 1; i--)
		max_heapify(a, i, heap_size);
}

void heap_sort(long *a, long len){
	long heap_size = len;
	build_max_heap(a, len);
	for(long i = len; i >= 2; i--){
		long t = a[i];
		a[i] = a[1];
		a[1] = t;
		
		heap_size -= 1;

		max_heapify(a, 1, heap_size);
	}
}

void print(long *a, long len){
	for(long i = 1; i <= len; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	while(cin>>n>>k){
		a = new long[k+1];
		long heap_size = 1;
		long t;
		k = n > k? k: n;
		for(long i = 0; i < n; i++){
			cin>>t;
			if(heap_size <= k){
				if(heap_size == k)
					build_max_heap(a,k);
				a[heap_size] = t;
				heap_size++;
			}else{
				if(t < a[1]){
					a[1] = t;
					//build_max_heap(a, k);
					max_heapify(a,1,k);
				}
			}
		}
		heap_sort(a, k);
		print(a, k);
		delete []a;
	}
	return 0;
}