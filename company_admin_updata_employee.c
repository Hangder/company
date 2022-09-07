#include <stdio.h>
#include "company_code.h"

void updata_employee(void)
{	
	int jb;

	printf("\n******当前为修改员工信息界面******\n");
	while(1)
	{
		printf("\n请输入您想修改的员工工号:");

                if(scanf("%d", &jb) != 1)
                {
                        printf("\n输入的员工工号有误!");
			while(getchar() != '\n');
			continue;
                }
		
		
		if(!is_employee_exist(jb))
		{
			printf("\n工号'%d'的员工信息不存在,修改失败!\n", jb);
		}
		else
		{
			struct employee e = {jb};
			printf("\n请按照提示输入员工信息\n");

                        printf("请输入员工的名字:");
                	scanf("%s", e.name);
               	 	getchar();

			printf("请输入员工的性别(0表示女生，1表男生):");
                	scanf("%c", &e.sex);
                	clear_input;

                	printf("请输入员工的身份证号码:");
                	scanf("%s", e.ID);
                	clear_input;

                	printf("请输入员工的电话号码:");
                	scanf("%s", e.phone_number);
               	 	clear_input;
printf("请输入员工联系人姓名: ");
                	scanf("%s", e.linkman_name);
                	clear_input;

                	printf("请输入员工联系人电话号码: ");
                	scanf("%s", e.linkman_pn);
                	clear_input;

                	printf("请输入员工联系人的邮箱: ");
                	scanf("%s", e.postbox);
                	clear_input;

                	printf("备注: ");
                	scanf("%s", e.remarks);
                	clear_input;

			if(updata_employee_from_file(&e) == 1)
			{
				printf("\n成功修改员工信息\n");
			}
			else 
			{
				printf("\n修改员工信息失败\n");
			}	
			
			printf("\n是否继续修改(y/n)");
			getchar();
			if(getchar() != 'y') break;
		}

	}
}

int updata_employee_from_file(struct employee* p)
{
	struct employee e1;
        int flag = 0;
        
	FILE* fp = fopen("employee_data", "r+b");

        if(fp == NULL) return 0;

        while(fread(&e1, sizeof(e1), 1, fp))
        {
                if(e1.job_number == p->job_number)
                {
                        fseek(fp, -sizeof(e1), SEEK_CUR);
                        fwrite(p, sizeof(struct employee), 1, fp);
                        break;
                }
		flag = 1;
	}
                fclose(fp);
		return flag;
}
