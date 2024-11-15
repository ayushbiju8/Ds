#include <stdio.h>

void printArray(int* A,int n){
    for (int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
}
int partition(int * A,int low,int high){
    int pivot = A[low];
    int i = low+1;
    int temp;
    int j = high;
    while (i<=j){ 
        while (i <= high && A[i] <= pivot) {
            i++;
        }
        while (j >= low && A[j] > pivot) {
            j--;
        }
        if (i<j){
            temp = A[i];
            A[i]= A[j];
            A[j]=temp;
        }
    }
    A[low] = A[j];
    A[j] = pivot;
    return j;
}

void quickSort(int A[],int low,int high){
    if (low<high){
        int partitionIndex = partition(A,low,high);
        quickSort(A,low,partitionIndex-1);
        quickSort(A,partitionIndex+1,high);
    }
    
}


int main(){
    int intArray[] = {1,2,33,22,1,5,87,33};
    int n = sizeof(intArray)/sizeof(int);
    // printArray(intArray,n);
    quickSort(intArray,0,n-1);
    printArray(intArray,n);
}