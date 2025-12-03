#include<stdio.h>

int main(){
    int n,i;
    printf("Enter the value of array ");
    scanf("%d",&n);
    int arr[n];
    
    printf("\nEnter the values in the array\n");
    for( i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    
    int len = sizeof(arr)/sizeof(arr[0]);
    for( i = 0 ; i<len-1 ; i++){
        for( int j = 0 ; j<len-1-i ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i =0 ; i<len ; i++){
        printf("%d\t",arr[i]);
    }
    
    int s;
    printf("\nEnter the value you want to search ");
    scanf("%d",&s);
    
    for( i =0 ; i<len ; i++){
        if(arr[i]==s){
            printf("The element is at index %d",i);
            break;
        }   
    }
    if( i == len){
        printf("Element not found");
    }
}
