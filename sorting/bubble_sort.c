/*
                                            Bubble sort

                                Bubble sort is a simple sorting algorithm. 
                                This sorting algorithm is comparison-based algorithm in which each pair of adjacent elements is
                                 compared and the elements are swapped if they are not in order. This algorithm is not suitable for large data sets as its average and worst case complexity are of Ο(n2) where n is the number of items.
                            +------------+-----------+--------------+------------+
                            | Complexity | Best Case | Average Case | Worst Case |
                            +------------+-----------+--------------+------------+
                            |    Time    |   O(n^2)  |    O(n)      |   O(n^2)   |
                            +------------+-----------+--------------+------------+
                            |        Worst case space complexity    |    O(1)    |
                            +---------------------------------------+------------+

*/
#include<stdio.h>
int main(){
    int i, j,temp;   
    int a[] = { 98,2,6,1,64,38,73,82,1002,85,43,87};   
    int n=sizeof(a)/sizeof(a[0]);
    for(i = 0; i<n; i++){  
        for(j = i+1; j<n; j++){  
            if(a[j] > a[i]){  
                temp = a[i];  
                a[i] = a[j];  
                a[j] = temp;   
            }   
        }   
    }
       
    printf("Sorted Element List \n");  
    for(i = 0; i<n; i++){  
        printf("%d\n",a[i]);  
    } 
}
