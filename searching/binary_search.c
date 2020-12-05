/*  
                                         Binary search       
                    +------------+-----------+--------------+------------+
                    | Complexity | Best Case | Average Case | Worst Case |
                    +------------+-----------+--------------+------------+
| Time       |  O(1)     |   O(log n)   | O(log n)   | 
+------------+-----------+--------------+------------+
|  	 Worst case space complexity    |    O(1)    |
+---------------------------------------+------------+

*/

#include<stdio.h>
int main(){
    int i,start,mid,end,element;
    int binary_search_array[] = {10,15,28,32,45,49,52,58,64,78,89,94,99};
    start = 0;
    end = sizeof(binary_search_array)/sizeof(binary_search_array[0]);
    printf("Input Element to search\n");
    scanf("%d",&element);

    do{
        mid = (int) ((start + end) / 2);
        if(binary_search_array[mid] == element){
            printf("%d find a %d",element,mid+1);
            break;
        }else if(binary_search_array[mid] > element){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    while(start <= end);

    if(start > end)
        printf("Failed");
   return 0;
}
