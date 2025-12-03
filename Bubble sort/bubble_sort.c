#include<stdio.h>

int main(){
    int n;
    printf("Enter the value of array");
    scanf("%d",&n);
    int arr[n];
    
    printf("\nEnter the values in the array");
    for(int i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0 ; i<len-1 ; i++){
        for(int j = 0 ; j<len-1-i ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i =0 ; i<len ; i++){
        printf("%d ",arr[i]);
    }
}
