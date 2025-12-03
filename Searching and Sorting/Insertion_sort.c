#include<stdio.h>

int main(){
    
    // Insertion  Sort
    int n,i,temp;
    printf("Enter the value of array ");
    scanf("%d",&n);
    int arr[n];
    
    printf("\nEnter the values in the array\n");
    for( i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    
    // main logic
    int j , min ;
    for(i=0 ; i<n ; i++){
        temp = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
    
    // for printing array
    for(i=0 ; i<n ; i++){
        printf("%d\t",arr[i]);
    }
}
