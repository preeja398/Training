#include<stdio.h>

struct employee
{
	char employeeName[50];
	int employeeId;
};

int main()
{
	FILE *fp=NULL;
	struct employee emp[2];
	int i;
	for(i=0;i<2;i++)
{
	printf("Enter the employee details\n");
	printf("Name:");
	scanf("%s",emp[i].employeeName);
	printf("Id:");
	scanf("%d",&emp[i].employeeId);
}

fp=fopen("file.bin","wb");
if(fp==NULL)
{
	printf("error in open file in write mode");
}
else
{
	for(i=0;i<2;i++)
 fwrite(&emp[i],sizeof(struct employee),1,fp);
}

fp=fopen("file.bin","rb");
{
	if(fp==NULL)
	printf("error open filn in read mode");
else
{
for(i=0;i<2;i++)
{
fread(&emp[i],sizeof(struct employee),1,fp);
printf("Employee name:%s\tEmployee id:%d\n",emp[i].employeeName,emp[i].employeeId);
}
}
}
}

