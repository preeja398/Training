#include<stdio.h>
#include<stdlib.h>

struct Employee {
	char employeeName[50]; 
	int employeeId;
};

int main() {
	FILE *fp = NULL;
	int n;
	printf("enter number of employee:"); 
	scanf("%d", &n);
	struct Employee emp[n];
	int index;
	for(index = 0; index < n; index ++) { 
		printf("Enter the employee details\n"); 
	        printf("Name:");
                scanf("%s", emp[index].employeeName);
                printf("Id:");
                scanf("%d", &emp[index].employeeId);
        }
        fp=fopen("file1.bin", "wb");
        if(fp == NULL) {
		printf("error in open file in write mode");
        } else {
	for(index = 0; index < n; index ++) {
        	fwrite(&emp[index], sizeof(struct Employee), n, fp);
		}
	fclose(fp);	
        }
	fp = fopen("file1.bin", "rb");
        if(fp == NULL) {       
		printf("error open file in read mode");
	} else {
	        for(index = 0; index < n; index ++) {
                fread(&emp[index], sizeof(struct Employee), n, fp);
		printf("Employee name:%s\tEmployee id:%d\n", emp[index].employeeName, emp[index].employeeId);
		}

	}
	fclose(fp);	
	
}


