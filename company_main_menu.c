#include <stdio.h>
#include "company_code.h"
#include <stdlib.h>

//主界面
void admin_menu(void)
{
	system("clear");

		//提供一个用户界面
		printf("\n**********主界面**********\n");
		printf("\n***操作提示：\n");
		printf("\n*录入员工信息请输入1\n");
		printf("\n*删除员工信息请输入2\n");
		printf("\n*修改员工信息请输入3\n");
		printf("\n*查询员工信息请输入4\n");
		printf("\n*添加普通用户请输入5\n");
		printf("\n*删除普通用户请输入6\n");
		printf("\n*更改普通用户信息请输入7\n");
		printf("\n*退出系统请输入0\n");
}

void cu_menu(void)
{	
	system("clear");
	printf("\n**********主界面**********\n");
        printf("\n***操作提示：\n");
        printf("\n*查询个人信息请输入8\n");
        printf("\n*更改自己密码信息请输入9\n");
        printf("\n*退出系统请输入0\n");	
}


