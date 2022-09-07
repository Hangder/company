#include <stdio.h>
#include <string.h>
#include "company_code.h"

void delete_employee(void)
{
	int jb;
	printf("\n******当前为删除员工信息界面******\n");
	while(1)
	{
		printf("\n请输入您想删除的员工工号:");
		if(scanf("%d", &jb) != 1)
		{
			printf("\n输入的员工工号有误,请重新输入!\n");
		}

		if(del_employee_from_file(jb) == 1)
		{
			printf("\n成功删除员工信息!\n");
		}
		else
		{
			printf("\n删除失败!\n");
		}
			
		printf("\n是否继续删除?(y/n)");
		getchar();
		if(getchar() != 'y') break;
	}
	
}

int del_employee_from_file(int job_number)
{
	struct employee e1;
	int flag = 0;
	
	FILE* fp = fopen("employee_data","r+b");
	
	if(fp == NULL) return 0;
	
	while(fread(&e1, sizeof(e1), 1, fp))
	{
		if(e1.job_number == job_number)
		{
			fseek(fp, -sizeof(e1), SEEK_CUR);
			memset(&e1, 0, sizeof(e1));
			fwrite(&e1, sizeof(e1), 1, fp);
			flag = 1;
			break;
		}
	
	}
	fclose(fp);
	return flag;  
}
