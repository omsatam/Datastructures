#include<stdio.h>
#include<stdlib.h>

// a function for showing the array
void show_array(int *arr,int n){
    printf("\n");
    for (int i=0;i<n;i++){
         printf("%d ",*(arr+i));
     }
}
// a function for deleting element at particular index
void delete_array(int *arr,int *n,int index){
    int temp;
    int j= *n;
    // arr = (arr + 4*j);
    for(int i=index-1;i<*n-1;i++){
        *(arr+i) = *(arr+i+1);
    }
    *n-=1;
    show_array(arr, *n)  ;
}
// a function to insert at particular index in array
void insert_array(int *arr,int *n,int index,int element){
    int temp;
    for(int i=*n;i>=index;i--){
    //    printf("%d\n",*arr); 
        *(arr + i) = *(arr + i - 1 );
        // arr -= sizeof(int);
    }

    *(arr + index - 1) = element;
    *n+=1;
    show_array(arr, *n)  ;
}



int main()
{
    int *arr;
    int max_size;
    int *n,i;
    int element;
    printf("Enter the maximum size of an array\n");
    scanf("%d",&max_size);
     arr = (int *)malloc(max_size * sizeof(int));
     printf("How many elements you want to enter now\n");
     scanf("%d",n);
     printf("Enter the elements of an array\n");
     for (i=0;i<*n;i++){
         scanf("%d",(arr+i));
     }
     show_array(arr,*n);
    //  printf("\n%d",*n);
    
     insert_array(arr,n,3,45);
    //  printf("\n%d",*n);
     delete_array(arr,n,3);
//      printf("\n%d",*n);
// }