#include <stdio.h>

int * bubbleSort(int * intArr,int n){
    int temp;
    for (int i = 0; i < n-1; i++){
        for (int j=0;j< n-1-i ; j++){
            if (intArr[j]>intArr[j+1]){
                temp = intArr[j];
                intArr[j]=intArr[j+1];
                intArr[j+1] = temp;
            }
        }
    }
    return intArr;
}

int * display(int * intArr,int n){
    for (int i=0;i<n;i++){
        printf("%d ",intArr[i]);
    }
}

int main(){
    int integerArray[] = {10,13,12,4,1,78,21,1};
    int n = 8;
    bubbleSort(integerArray,n);
    display(integerArray,n);
}

/*
Bubble sort

For loop for num of iterations (n-1)
For loop for swapping eac (n-i-1)
If A[i]>A[i+1]
    swap

*/