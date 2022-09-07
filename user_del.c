#include <stdio.h>
#include <string.h>
#include "user.h"

//删除用户
void user_del(void)
{
        char user_name[31];
	while(1)
	{
		printf("\n请输入要删除的普通用户名: ");
		scanf("%30s", user_name);

		user_info u;
		FILE* fp = fopen("user_data", "r+b");
		int del_success = 0;
		if(fp == NULL)
		{
			perror("open user_data fail\n");
		}

		while(fread(&u, sizeof(u), 1, fp))
		{
			if(u.user_role == 2 && strcmp(user_name, u.user_name) == 0)
			{
				fseek(fp, -sizeof(u), SEEK_CUR);
				memset(&u, 0, sizeof(u));
				fwrite(&u, sizeof(user), 1, fp);
				del_success = 1;
				break;
			}
		}
		fclose(fp);
		if(del_success)
			printf("\n删除普通用户 %s 成功！\n", user_name);
		else
			printf("\n普通用户%s不存在, 删除失败！\n", user_name);
			
		printf("\n是否继续删除?(y/n)");
		getchar();
		if(getchar() != 'y') break;
	}
}

