#include<stdio.h>
#include<stdlib.h>

void call_val(float f1, float f2);
void call_ref(float *f1, float *f2);

int main() {
	float f1, f2;
	printf("Enter the Float numbers : ");
	scanf("%f%f",&f1,&f2);
        call_val(f1,f2);
	call_ref(&f1,&f2);
	return 0;
}
void call_val(float f1, float f2) {
	printf("Sum of values by call_by_value : %f\n", f1 + f2);
}
void call_ref(float *f1, float *f2) {
	printf("Sum of values by call_by_ref : %f\n", *f1 + *f2);

}

