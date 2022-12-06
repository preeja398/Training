#include<stdio.h>

struct Employee{ 
	char employeeName[50]; 
	int employeeId;
};
int main()
{
	FILE *fp = NULL;
	int n;
	printf("enter number of employee:"); 
	scanf("%d",&n);
	struct employee emp[n];
	int i;
	for(i = 0;i < n;i++){ 
		printf("Enter the employee details\n"); 
	        printf("Name:");
                scanf("%s",emp[i].employeeName);
                printf("Id:");
                scanf("%d",&emp[i].employeeId);
        }
        fp=fopen("file1.bin","wb");
        if(fp == NULL){
		printf("error in open file in write mode");
        }
        else{
		for(i = 0;i < n;i++){
        	fwrite(&emp,sizeof(struct employee),n,fp);
		}
        }
	fp=fopen("file1.bin","rb");
        if(fp == NULL){      
		printf("error open filn in read mode");
	}
	else{
		for(i = 0;i < n;i++){
			fread(&emp[i],sizeof(struct employee),n,fp);
			printf("Employee name:%s\tEmployee id:%d\n",emp[i].employeeName,emp[i].employeeId);
		}

		}
	fclose(fp);	
	}

}


