#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "company_code.h"


//保存员工信息
void save_employee(const struct employee* e)
{
	FILE* fp = fopen("employee_data", "ab");
	fwrite(e, sizeof(struct employee), 1, fp);
	fclose(fp);
}

//清空缓冲区
void clear_input(void)
{
    while(getchar() != '\n');
}

//判断员工信息是否存在
int is_employee_exist(int job_number)
{
	struct employee e;
	int flag = 0;
	FILE *fp = fopen("employee_data", "rb");
	if(fp == NULL) return 0;

	while(fread(&e, sizeof(e), 1, fp))
	{
		if(e.job_number == job_number)
		{
			fwrite(&e, sizeof(e), 1, fp);

			flag = 1;
			break;
		}
	}

		fclose(fp);

		return flag;
}
