#include <stdio.h>
#include <stdlib.h>
#include "company_code.h"

int main()
{		
	int op;		
 	
	printf("\n******欢迎使用DerDer公司通讯录管理信息系统！******\n");
	
	main_menu();
	
	while(1)
         {
		printf("\n请输入您操作的编号: ");
         	
		if(scanf("%d", &op) != 1)
         	{
         		while(getchar() !='\n');
         		op = -1;
         	}

         	switch(op)
         	{
			case 0:
			{
				printf("\n感谢您的使用,期待和您下次再见!\n");
         			exit(0);//正常退出
         			break;
			}
			
			case 1:
			{
				input_employee();
				main_menu();
				break;
			}
			
			case 2:
			{
				delete_employee();
				main_menu();
				break;
			}

			case 4:
			{
				search_employee();
				main_menu();
				break;
			}
			default:
			{
				printf("\n您输入的编号有问题，请确认后重新输入!\n");
				break;
			}
		}
	}
}
