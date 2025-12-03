#include <stdio.h>

void bubble_sort(int arr[],int n){
    int swap;
    int temp;
    
    for(int i = 0 ; i<n-1 ; i++){
        swap = 0;
        
        for(int j = 0 ; j<n-1-i ; j++){
            
            if(arr[j]>arr[j+1]){
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            
            swap = 1;
            }

        }
        if(swap == 0){
            break;
        }
    }
}

void printarray(int *n, int s){
    for(int i =0 ; i<s ; i++){
        printf("%d ",n[i]);
    }
}

int main()
{
    int a[] ={3,4,67,5,7};
    int size = 5;
    bubble_sort(a,size);
    printarray(a,size);

    return 0;
}
