#include<stdio.h>

struct Employee{
	char employeeName[50];
	int employeeId;
};

int main(){
    FILE *fp = NULL;
    struct Employee emp[2];
    int index;
    for(index = 0; index < 2; index ++){
	    printf("Enter the employee details\n");
	    printf("Name:");
	    scanf("%s", emp[index].employeeName);
	    printf("Id:");
	    scanf("%d", &emp[index].employeeId);
    }
    
    fp = fopen("file.bin", "wb");
    if(fp == NULL) {
	    printf("error in open file in write mode");
    } else {
	    for(index = 0; index < 2; index ++){
		    fwrite(&emp[index], sizeof(struct Employee), 1, fp);
	    }
	    fclose(fp);
    }

    fp = fopen("file.bin", "rb");
    if(fp == NULL) {
	    printf("error open filn in read mode");
    } else {
	    for(index = 0; index < 2; index ++) {
		    fread(&emp[index], sizeof(struct Employee), 1, fp);
		    printf("Employee name:%s\tEmployee id:%d\n", emp[index].employeeName, emp[index].employeeId);
	    }
	    fclose(fp);
    }
}

