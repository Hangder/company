#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "user.h"
//添加普通用户
void user_add(void)
{
	user_info u;
	int tmp = 0;
	char user_pass[31], user_pass_check[31];
	while(1)
	{
		printf("\n请按照下面提示输入普通用户信息。\n");
		while(1)
		{
			printf("用户名: ");
			scanf("%s", u.user_name);
			
			tmp = check_user_name(u.user_name);
			if(tmp == 1)
			{
				printf("用户名已存在，请重新输入\n");
			}
			else break;
		}

		while(1)
		{
			strcpy(user_pass, getpass("密码: "));
			strcpy(user_pass_check, getpass("再次输入密码："));

			if(strcmp(user_pass, user_pass_check) == 0) break;

			printf("两次输入的密码不一样，请确认后重新输入！\n");
		}
		
		md5_encode(user_pass, strlen(user_pass), u.user_pass);
		u.user_role =  2;
		u.reg_time = time(NULL);
		u.last_login_time = 0;//没有登录过
		
		FILE* fp = fopen("user_data","ab");
		if(fp == NULL)
		{
			perror("open user_data fail\n");
		}

		fwrite(&u, sizeof(u), 1, fp);
		fclose(fp);
		printf("\n成功添加普通用户信息!\n");
		
		printf("\n是否继续添加?(y/n)");
        	getchar();
        	if(getchar() != 'y') break;
	
	} 

}

//
int check_user_name(const char* user_name)
{
	user_info u;
        int check_sucess = 0;
        FILE* fp = fopen("user_data", "rb");

        if(fp == NULL) return 0;
	
        while(fread(&u, sizeof(u), 1, fp) != 0)
        {
                if(strcmp(u.user_name, user_name) == 0)
             	{
                        check_sucess = 1;
                        break;
                }
        }
        fclose(fp);
        return check_sucess;
}

