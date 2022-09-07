#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "company_code.h"

void search_employee(void)
{
        int jb;
        printf("\n***欢迎使用查询模式: ***\n");
        while(1)
        {
                printf("\n请输入您想查询员工的工号:");
                if(scanf("%d", &jb) != 1)
		{
			printf("\n您输入的员工工号有问题，请重新输入！(0表示退出)\n");
			while(getchar() != '\n');
			continue;
		}
		
		if(jb == 0) break;//输入0退出	

                struct employee* p = find_employee(jb);
                if(p == NULL)
                {
                        printf("工号不存在,未找到员工信息(0表示退出)\n");
                        continue;
                }
			printf("\n***员工信息如下:***\n");
                        printf("员工工号为:%d\n", p->job_number);
                        printf("员工名字为:%s\n", p->name);
                        printf("员工性别为:%s\n", p->sex == 0?"女生":"男生");
                        printf("员工身份证号码为:%s\n", p->ID);
                        printf("员工电话号码为:%s\n", p->phone_number);
			printf("员工联系人为:%s\n", p->linkman_name);
			printf("员工联系人电话号码为:%s\n", p->linkman_pn);
			printf("员工联系人邮箱为:%s\n", p->postbox);
			printf("备注:%s\n", p->remarks);
                        free(p);
			
			printf("\n是否继续查询?(y/n)");
			getchar();
			if(getchar() != 'y') break;
	}
}

//查找
struct employee* find_employee(int job_number)
{
        struct employee e;
        int flag = 0;
        FILE* fp = fopen("employee_data","rb");
	
	if(fp == NULL) return NULL;

        while(fread(&e, sizeof(e), 1, fp))
        {
                if(e.job_number == job_number)
                {
                        flag = 1;
                        break;
                }
        }

        fclose(fp);
	
	if(flag)
        {
                struct employee* p = (struct employee*)malloc(sizeof(struct employee));
                memcpy(p, &e, sizeof(e));
                return p;
        }
}
