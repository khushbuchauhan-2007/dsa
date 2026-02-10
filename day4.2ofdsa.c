#include<stdio.h>
#define N 100
int main() {
    int n,arr[n],val;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);

    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    printf("Enter the value to remove: ");
    scanf("%d",&val);

    int k=0;
    for(int i=0;i<n;i++) {
        if(arr[i]!=val) {
            arr[k]=arr[i];
            k++;
        }
    }
    printf("Number of elements after removal: %d\n",k);
    printf("Array after removal:\n");
    for(int i=0;i<k;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}