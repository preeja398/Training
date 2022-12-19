#include<stdio.h>

int main() {
    int array[50];
    int size;
    int index;
    int search;
    int first;
    int last;
    int middle;

    printf("Enter the no.of elements:\n");
    scanf("%d", &size);
    printf("Enter the elements in sorted format:\n");

    for (index =0; index < size; index ++ ) {
        scanf("%d", &array[index]);
    }
    printf("\nEnter the search element:\n");
    scanf("%d", &search);
    first = 0;
    last = size - 1;
    middle = (first + last) / 2;
    
    while(first <= last) {
        if (search == array[middle]) {
	    printf("Element %d in array[%d]\n", search, middle);
	    break;
	} else if (search < array[middle]) {
	      last = middle - 1;
	} else {
  	      first = middle + 1;
	}
        middle = (first + last) / 2;
    }

    if (first > last) {
        printf("Search element not found\n");
    }
}    

