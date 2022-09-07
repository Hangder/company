#include <stdio.h>
#include <stdlib.h>
#include "company_code.h"
#include "user.h"
int main()
{		
	int op, id;		
 	system("clear");
	
	welcome();
	
	while(1)
         {
		printf("\n请输入您操作的编号: ");
         	
		if(scanf("%d", &op) != 1)
         	{
         		while(getchar() !='\n');
         		op = -1;
         	}

	if(se == 2)
	{
		if(op == 1 || op == 2 || op == 3 || op == 4 || op == 5 || op == 6 || op == 7)
		{
			printf("权限不足 请重新输入\n");
			continue;
		}
	}
         	switch(op)
         	{
			case 0:
			{
				printf("\n感谢您的使用,期待和您下次再见!\n");
         			exit(0);//正常退出
			}
         		break;
			
			
			case 1:
			{
				input_employee();
				admin_menu();
			}
			break;
			
			
			case 2:
			{
				delete_employee();
				admin_menu();
			}
			break;
			

			case 3:
			{
				updata_employee();
				admin_menu();
			}
			break;
			

			case 4:
			{
				search_employee();
				admin_menu();
			}
			break;

			case 5:
			{
				//添加普通用户
				user_add();
				admin_menu();
			}
			break;

			case 6:
			{
				//删除普通用户
				user_del();
				admin_menu();
			}
			break;

			case 7:
			{	
				//修改普通用户信息
				updata_user_info();
				admin_menu();
			}
			break;

			case 8:
			{
				 cu_search_employee();
				 cu_menu();
			}
			break;

			case 9:
			{
				user_cu_updata();
				cu_menu();
			}


			default:
			{
				printf("\n您输入的编号有问题，请确认后重新输入!\n");
			}
			break;
			
		}
	}
}
