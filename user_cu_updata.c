#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "user.h"
#include <string.h>
#include <time.h>

int user_cu_updata(void)
{	
	char user_name[31], user_pass[31], user_pass_check[31];
	while(1)
        {
                printf("\n请输入您的用户名:");

                if(scanf("%s", user_name) != 1)
                {
                        printf("\n输入的有误!");
                        while(getchar() != '\n');
                        continue;
                }
			
		user_info u;
	        strcpy(u.user_name, user_name);

		while(1)
		{	
			strcpy(user_pass, getpass("密码: "));
			strcpy(user_pass_check, getpass("再次输入密码："));

			if(strcmp(user_pass, user_pass_check) == 0) break;	
			printf("两次输入的密码不一样，请确认后重新输入！\n");
		}	

		md5_encode(user_pass, strlen(user_pass), u.user_pass );
	
		if(updata_user_from_file(&u) == 1)
		{	
			printf("成功修改您密码，请牢记新密码！\n");
		}
		else
                {
                        printf("\n修改员工信息失败\n");
                }
                        
		printf("\n是否继续修改(y/n)");
                getchar();
                if(getchar() != 'y') break;
	}
}

int updata_user_from_file(user_info* p)
{
        user_info e1;
        int flag = 0;

        FILE* fp = fopen("user_data", "r+b");

        if(fp == NULL) return 0;

        while(fread(&e1, sizeof(e1), 1, fp))
        {
		if(strcmp(e1.user_name, p->user_name) == 0)
                {
         		fseek(fp, -sizeof(e1), SEEK_CUR);
                        fwrite(p, sizeof(e1), 1, fp);
	 		flag = 1;
			break;
                }
        }
                fclose(fp);
                return flag;
}

