#include "iostream"

using namespace std;

void swap(int a[], int i, int j){
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void bubbleSort(int a[], int n){
	int count = 0;
	for(int i=0;i<n;i++){
		count=0;
		for(int j=i+1;j<n;j++,count++){
			if(a[i] > a[j]){
				swap(a,i,j);
			}
		}
		if(!count)
			break;
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	bubbleSort(a,n);
	
	for(int i=0;i<n;i++){
		cout<<a[i];
	}

	return 0;
}

