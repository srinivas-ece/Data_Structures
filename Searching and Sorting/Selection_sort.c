#include<stdio.h>

int main(){
    
    // Selection Sort
    int n,i;
    printf("Enter the value of array ");
    scanf("%d",&n);
    int arr[n];
    
    printf("\nEnter the values in the array\n");
    for( i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    
    int j , min , temp;
    for(i=0 ; i<n-1 ; i++){
        min = i;
        for(j=i+1 ; j<n ; j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        if(i != min){
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    for(i=0 ; i<n ; i++){
        printf("%d\t",arr[i]);
    }
}
