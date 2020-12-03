/* Program to check whether the array is sorted or not using recursion */

//Time Complexity O(n) 
//Space Complexity O(n) for recursive stack space

#include<stdio.h>
int is_array_in_sorted_order(int a[],int n){

    if(n==1)    return 1;
    
    return (a[n-1]<a[n-2])?0:is_array_in_sorted_order(a,n-1);
}
int main(){
    int arr[]={1,2,3,4,5};

    int size=sizeof(arr)/sizeof(arr[0]);

    printf("%d",is_array_in_sorted_order(arr,size));
}