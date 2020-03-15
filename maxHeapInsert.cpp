#include<iostream>
#include<cmath>
using namespace std;
int Heapify(int A[], int i, int size){
	int l=2*i;
	int r=2*i+1;
	int big=i;
	if(A[l]>A[r]){
		if(l<=size && A[l]>A[i])
			big = l;
	}
	else if(A[l]<A[r]){
		if(r<=size && A[r]>A[i])
			big = r;
	}
	if(i != big){
		int temp = A[i];
		A[i]=A[big];
		A[big]=temp;
		Heapify(A,big,size);
	}
	return 0;
}
int constructHeap(int A[], int size){
	int x = floor((float)(size/2));
	for(int i=x;i>=1;i--)
		Heapify(A,i,size);
	return 0;
}
int percolateUp(int A[],int i, int size){
	while(size>1 && A[size]>A[i]){
		int temp = A[i];
		A[i] = A[size];
		A[size]= temp;
		size=i;
		i=floor((float)(i/2));
	}
}
int insert(int A[], int size){
	int key;
	cout<<"\nEnter the key : "; cin>>key;
	A[++size]=key;
	if(size==19)      // capacity-1
		return 1;
	int i = floor((float)(size/2));
	percolateUp(A,i,size);
	cout<<"\n Do u wanna insert any key?\n(ans.)Y=1 or N=0\n";
	cin>>key;
	if(key==1){
		cout<<"The heap After inserting is"<<endl;
		for(int i=1;i<=size;i++)
			cout<<A[i]<<"|";
		insert(A,size);
	}
	else{
		cout<<"\nThe heap After inserting is"<<endl;
		for(int i=1;i<=size;i++)
			cout<<A[i]<<"|";
	}
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
		cout<<"The Max-heap is"<<endl;
		for(int i=1;i<=size;i++)
			cout<<A[i]<<"|";
	insert(A,size);
	return 0;
}
