#include<iostream>
#include<cmath>
using namespace std;

int Heapify(int A[], int i, int size){
	int l=2*i;
	int r=2*i+1;
	int small=i;
	if(A[l]<A[r]){
		if(l<=size && A[l]<A[i])
			small = l;
	}
	else if(A[l]>A[r]){
		if(r<=size && A[r]<A[i])
			small = r;
	}
	if(i != small){
		int temp = A[i];
		A[i]=A[small];
		A[small]=temp;
		Heapify(A,small,size);
	}
	return 0;
}

int constructHeap(int A[], int size){
//	int x = floor((float)(size/2));
	int x = size/2;
	for(int i=x;i>=1;i--)
		Heapify(A,i,size);
	return 0;
}

int main(){
	cout<<"Enter Array size\n";
	int size;
	cin>>size;
	int A[size];
	cout<<"Enter elements\n";
	for(int i=1;i<=size;i++)
		cin>>A[i];
	constructHeap(A,size);
	cout<<"The heap is"<<endl;
	for(int i=1;i<=size;i++)
		cout<<A[i]<<"|";
	return 0;
}
