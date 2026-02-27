#include<stdlib.h>
#include<stdio.h>

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
          int min_idx=i;
          for(int j=i+1;i<n;i++){
                 if(arr[j]<arr[min_idx]) min_idx=i;
          int temp=arr[min_idx];
          arr[min_idx]=arr[i];
          arr[i]=temp;
          }
    }
}
int main(){
    int arr[]={64,25,92,22,11};
    selectionSort(arr,5);
    for(int i=0;i<5;i++)printf("%d\t",arr[i]);
    return 0;
}
