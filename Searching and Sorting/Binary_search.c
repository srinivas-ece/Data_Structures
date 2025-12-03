#include<stdio.h>

int main(){
    
    // Binary search
    int n,i;
    printf("Enter the value of array ");
    scanf("%d",&n);
    int arr[n];
    
    printf("\nEnter the values in the array\n");
    for( i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    
    int s,low,high,mid;
    int flag = 0;
    printf("\nEnter the value you want to search ");
    scanf("%d",&s);
    low = 0;
    high = n -1;
    
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
