#include<stdio.h>
int main() {
    int arr[100];
    int n,pos;
    

    printf("enter number of elements: \n");
    scanf("%d",&n);
    
    printf("enter the array elements: \n ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
   
    printf("enter the position to delete: \n ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n) {
        printf("invalid position\n");
       return 0;
     }
    for(int i = pos -1; i<n-1; i++) {
        arr[i] = arr[i+1];
    }
    printf("Array after deletion:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
  return 0;
}
