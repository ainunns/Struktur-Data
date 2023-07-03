//Merge Sort
#include <bits/stdc++.h>
using namespace std;
void merge(int arr[],int al, int ar, int bl, int br){
	int size=br-al+1,temp[size],ti=0,ai=al,bi=bl;
	while((ai<=ar)&&(bi<=br)){
		if(arr[ai]<=arr[bi]){
			temp[ti]=arr[ai];
			ai++;
		} else {
			temp[ti]=arr[bi];
			bi++;
		} 
		ti++;
	}
	while(ai<=ar){
		temp[ti]=arr[ai];
		ai++;
		ti++;
	}
	while(bi<=br){
		temp[ti]=arr[bi];
		bi++;
		ti++;
	}
	for(int i = 0; i < size; i++)
		arr[al+i]=temp[i];
}
void mergesort(int arr[],int l, int r){
	if(l<r){
		int mid=(l+r)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,l,mid,mid+1,r);
	}
}
int main(){
	int bil[100],n;
	printf("Masukkan banyaknya data yang akan diurutkan: ");
	scanf("%d",&n);
	printf("Masukkan data-data yang akan diurutkan (dipisahkan spasi): \n");
	for(int i = 0 ; i < n; i++)
		scanf("%d", &bil[i]);
	printf("\nData sebelum diurutkan:\n\t");
	for(int i = 0; i < n; i++)
		printf("%d ", bil[i]);
	puts("");
	mergesort(bil,0,n-1);
	printf("Data setelah diurutkan:\n\t");
	for(int i = 0; i < n; i++)
		printf("%d ", bil[i]);
	puts("");
	system("pause");
	return 0;
}
