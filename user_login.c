#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "user.h"
#include <string.h>

user_info user;//全局变量，别的地方也可以用

int user_login(void)
{	
	int op = 0;
	char user_name[31], user_pass[31], user_pass_check[31];
	printf("\n请先登录！\n");
	printf("\n用户名: ");
	scanf("%s", user_name);

	//回显 
	strcpy(user_pass, getpass("密码: "));

	if(is_first_run() == 1)
	{
		//首次登录
		if(strcmp(user_name, "admin") != 0 || strcmp(user_pass, "1234") != 0)
		{
			printf("用户名或密码错误，登录失败！\n");
			exit(1);
		}
		else
		{
			printf("恭喜你，登录成功！\n");
			op = 1;
		}
	
		//登录成功
		printf("为了系统安全，请重新设置管理员用户名和密码。\n");
		
		printf("\n管理员用户名: ");
		scanf("%s", user_name);
		while(1)
		{	
			strcpy(user_pass, getpass("管理员密码: "));
			strcpy(user_pass_check, getpass("再次输入管理员密码："));

			if(strcmp(user_pass, user_pass_check) == 0) break;
			
			printf("两次输入的密码不一样，请确认后重新输入！\n");
		
		}

		strcpy(user.user_name, user_name);
		md5_encode(user_pass, strlen(user_pass), user.user_pass );
		user.user_role = 1;
		user.reg_time = user.last_login_time = time(NULL);
		
		FILE* fp = fopen("user_data","wb");
		if(fp == NULL)
		{
			perror("open user_data fail\n");
		}
		
		fwrite(&user, sizeof(user), 1, fp);
		
		fclose(fp);
		
		printf("成功修改密管理员密码，请牢记新密码！\n");
	}
	else
	{
		//非首次登录
		if(user_login_check(user_name, user_pass) == 0)
		{
			printf("用户名或密码错误，登陆失败！\n");
			exit(1);
		}
		//更新用户的最近登录时间
		user.last_login_time = time(NULL);
		updata_user_info();
		op = 1;
	}
		printf("\n恭喜你,登陆成功! %s您好！欢迎使用DerDer公司通讯录管理系统！\n", user_name);
		
		return op;
}

int is_first_run(void)
{
	FILE* fp = fopen("user_data", "rb");
	if(fp == NULL) return 1;
	fclose(fp);
	return 0;
}

int user_login_check(const char* user_name, const char* user_pass)
{
	user_info u;
	char user_pass_md5[33];
	int check_sucess = 0;
	FILE* fp = fopen("user_data", "rb");
     	
	md5_encode(user_pass, strlen(user_pass), user_pass_md5);//加密   
	
	if(fp == NULL) return 0;

	while(fread(&u, sizeof(u), 1, fp) != 0)
	{
		if(strcmp(u.user_name, user_name) == 0 && strcmp(u.user_pass, user_pass_md5) == 0)
		{
			//登录验证成功
			user = u;
			check_sucess = 1;
			break;
		}
	}
	fclose(fp);
	return check_sucess;
}
