#include<stdio.h>

int main(){
    
    // Bubble sort 
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


    // Binary Search
    int s,low,high,mid;
    int flag = 0;
    printf("\nEnter the value you want to search ");
    scanf("%d",&s);
    low = 0;
    high = len -1;
    
    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid]==s){
            printf("Found data at the index %d",mid);
            flag = mid;
            break;
        }
        else if(arr[mid]<s){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    
    
}
