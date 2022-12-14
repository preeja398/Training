#include<stdio.h>

struct Dates {
    int date;
    int month;
    int year;
};

struct Student {
    char name[50];
    int rollNumber;
    struct Dates birthday;
    struct Dates admission;
};

int main() {
    int number;
    int index=0;
    printf("Enter no.of student:");
    scanf("%d", &number);
    struct Student detail[number];
    printf("***Enter the student details***\n");	    
    
    for(index=0; index < number; index ++) {
        printf("Enter name of %d student:", index + 1);
	scanf("%s", detail[index].name);
	printf("Enter the roll number of %d student:", index + 1);
	scanf("%d", &detail[index].rollNumber);
	printf("Enter birth date month year of %d student:", index + 1 );
	scanf("%d%d%d", &detail[index].birthday.date, &detail[index].birthday.month, &detail[index].birthday.year);
	printf("Enter admission date month year of %d student:", index + 1);
	scanf("%d%d%d", &detail[index].admission.date, &detail[index].admission.month, &detail[index].admission.year);
    }
    
    for(index=0; index < number; index ++) {
        printf("Name of %d student:%s\n", index + 1, detail[index].name);
	printf("Roll number of %d student:%d\n", index + 1, detail[index].rollNumber);
	printf("Date of birth %d student:%d:%d:%d\n", index + 1, detail[index].birthday.date, detail[index].birthday.month, detail[index].birthday.year);
	printf("Date of admission %d student:%d:%d:%d\n", index + 1, detail[index].admission.date, detail[index].admission.month, detail[index].admission.year);
	printf("Age of %d student:%d\n", index + 1, detail[index].admission.year - detail[index].birthday.year);
	}
}

