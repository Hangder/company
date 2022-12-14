#include <stdio.h>
#include "company_code.h"

//增加员工信息
void input_employee()
{
        struct employee e;
        while(1)
        {
                printf("\n******按照下面提示输入员工信息******\n");
		while(1)
		{
			printf("请输入员工的工号:");
			scanf("%d", &e.job_number);
			
			if(is_employee_exist(e.job_number) == 1)
			{
				printf("该员工工号已存在，请重新输入！\n");
			}
			
			else break;
		}
                clear_input;
                
                
		printf("请输入员工的名字:");
                scanf("%s", e.name);
                getchar();

                printf("请输入员工的性别(0表示女生，1表男生):");
                scanf("%c", &e.sex);
                clear_input;
                
		printf("请输入员工的身份证号码:");
                scanf("%s", e.ID);
                clear_input;
		
		printf("请输入员工的电话号码: ");
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

                save_employee(&e);

                printf("\n录入成功\n");
                printf("\n是否继续录入?(y/n)");
                getchar();
                if(getchar() != 'y') break;//回到主界面
        }
}

