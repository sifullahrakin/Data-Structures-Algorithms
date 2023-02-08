#include <stdio.h>

int main() {

    ///initializing size of the array
    int size;
    printf("Enter Size of the Array: ");
    scanf("%d",&size);

    int a[size];
    int i;

    ///taking the array as input using for loop
    for (i=0; i<size; i++){
        scanf("%d",&a[i]);
    }

    ///printing the array
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }

    return 0;
}
