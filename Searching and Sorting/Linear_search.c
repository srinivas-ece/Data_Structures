#include<stdio.h>

int main(){
    int n,i;
    printf("Enter the array size ");
    scanf("%d",&n);
    int a[n];
    
    printf("\nEnter the elements in the array ");
    for(i = 0 ; i<n ; i++){
        scanf("%d",&a[i]);
    }
    
    int s;
    printf("Enter the element you want to search ");
    scanf("%d",&s);
    
    for(i=0 ; i<n ; i++){
        if(a[i] == s){
            printf("The element is at index %d",i);
            break;
        }
    }
    if(i == n ){
        printf("Not found");
    }
}
