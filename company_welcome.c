#include <stdio.h>
#include <stdlib.h>
#include "company_code.h"
#include "user.h"

int se = 0;

void welcome(void)
{
	system("clear");

	printf("\n-------------------------------------------------------------------------------------------------\n");
	printf("\n*******************************欢迎使用DerDer公司通讯录管理信息系统登录界面**********************\n");
	printf("\n-------------------------------------------------------------------------------------------------\n");
	printf("\n                                *** 1 表示管理员***                                              \n");
	printf("\n");
	printf("\n                                *** 2 表示普通用户***                                            \n");
	printf("\n-------------------------------------------------------------------------------------------------\n");		
	while(1)
	{	
		printf("\n请选择您的身份: ");
		if(scanf("%d", &se) != 1)
		{
			while(getchar() != '\n')
			se = -1;
		}
		else break;
	}
		switch(se)
		{
			case 1:
			{
				if(user_login() == 1 )
				{
					admin_menu();
					now_time();
				}
				else
				{
					printf("请重新登录！\n");
				}
			}
			break;

			case 2:
			{
				if(user_login() == 1)
				{
					cu_menu();
					now_time();

				}
				else
				{
					printf("请重新登录!\n");
				}
			}
			break;

			default:
			{
				 printf("\n您输入的编号有问题，请确认后重新输入!\n");
			}
		}
}
