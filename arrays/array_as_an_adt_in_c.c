//Array as an adt in c
#include<stdio.h>
#include<stdlib.h>
struct Array{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct Array * a, int tSize, int uSize){
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void show(struct Array *a){
    for (int i = 0; i < a->used_size; i++){
        printf("%d\n", (a->ptr)[i]);
    }
}

void setValues(struct Array *a){
    int n;
    for (int i = 0; i < a->used_size; i++){
        printf("Enter element %d", i);
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
    
}

int main(){
    struct Array arr;
    createArray(&arr, 100, 1);
    printf("set values ");
    setValues(&arr);
    printf("display function");
    show(&arr);
    return 0;
}
