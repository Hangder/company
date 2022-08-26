#include <stdio.h>
#include <string.h>
#include "company_code.h"

void delete_employee()
{
	int jb;
	printf("\n***当前为删除模式***\n");
	printf("\n请输入您想删除的员工工号:");
	if(scanf("%d", &jb) == 1)
	{
		printf("输入的员工工号有误!");
	}
	while(getchar() != '\n')

	if(del_employee_from_file(jb))
	{
		printf("\n成功删除员工信息!\n");
	}
	else
	{
		printf("\n删除失败!\n");
		printf("\n是否继续查询(y/n)\n");
		if(getchar() != 'y') break;
	}
	
}

static int del_employee_from_file(int job_number)
{
	struct employee e;
	int flag = 0;
	FILE* fp = fopen("employee data","r+b");
	if(fp == NULL) return 0;
	
	while(fread(&e, sizeof(struct employee), 1, fp))
	{
		if(e.job_number = job_number)
		{
			fseek(fp, -sizeof(e), SEEK_CUR);
			memset(&e, 0, sizeof(e));
			fwrite(&e, sizeof(e),1,fp);

			flag = 1;
			break;
		}
		
		fclose(fp);
		return flag;
	}
}
