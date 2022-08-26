#include <stdio.h>
#include "company_code.h"

//增加员工信息
void input_employee()
{
        struct employee e;
        while(1)
        {
                printf("\n******按照下面提示输入学生信息******\n");
                printf("请输入员工的工号:");
                scanf("%d", &e.job_number);
                clear_input;
                
		printf("请输入员工的密码:");
                scanf("%d", &e.password);
                clear_input;
                
		printf("请输入员工的名字:");
                scanf("%s", e.name);
                getchar();

                printf("请输入员工的性别(0表示女生，1表男生):");
                scanf("%c", &e.sex);
                clear_input;
                
		printf("请输入员工的身份证号码:");
                scanf("%ld", &e.ID);
                clear_input;
		
		printf("请输入员工的电话号码:");
                scanf("%d", &e.phone_number);
                clear_input;

                save_employee(&e);

                printf("\n录入成功\n");
                printf("\n是否继续录入?(y/n)");
                getchar();
                if(getchar() != 'y') break;//回到主界面
        }
}

