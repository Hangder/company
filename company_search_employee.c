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
                printf("请输入您想查询员工的工号:");
                scanf("%d", &jb);

                struct employee* p = find_employee(jb);
                if(p == NULL)
                {
                        printf("工号不存在,未找到员工信息\n");
                        continue;
                }
			printf("\n***员工信息如下:***\n");
                        printf("员工工号为:%d\n", p->job_number);
                        printf("员工密码为:%d\n", p->password);
                        printf("员工名字为:%s\n", p->name);
                        printf("员工性别为:%s\n", p->sex == 0?"女生":"男生");
                        printf("员工身份证号码为:%ld\n", p->ID);
                        printf("员工电话号码为:%d\n", p->phone_number);

                        free(p);
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
        return NULL;
}

