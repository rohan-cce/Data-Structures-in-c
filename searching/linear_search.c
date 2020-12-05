/*
                                                  Linear search 

                                    a linear search or sequential search is a method for finding an element within a list.
                                    It sequentially checks each element of the list until a match is found or the whole list
                                    has been searched. A linear search runs in at worst linear time and makes at most n comparisons,
                                       where n is the length of the list
                                +------------+-----------+--------------+------------+
                                | Complexity | Best Case | Average Case | Worst Case |
                                +------------+-----------+--------------+------------+
                                | Time       |    O(1)   |     O(n)     |    O(n)    |
                                +------------+-----------+--------------+------------+
  
*/
    #include<stdio.h>   
    int main ()  {  
        int item,n, i,flag=0; 
        printf("Enter number of Elements : \n");
        scanf("%d",&n);
        int a[n];
        printf("Enter the array : \n");
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        
        printf("Enter Element to search for : \n");  
        scanf("%d",&item);  
        for (i = 0; i< n; i++){  
            if(a[i] == item){  
                flag = i+1;  
                break;  
            }  
        }   
        if(flag != 0){  
            printf("\nItem found at location %d\n",flag);  
        }else{  
            printf("\nItem not found\n");   
        }  
    }   
