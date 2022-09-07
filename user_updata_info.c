#include <stdio.h>
#include <string.h>
#include "user.h"

//更改用户信息
void updata_user_info(void)
{
        user_info u;
        FILE* fp = fopen("user_data", "r+b");
        if(fp == NULL)
        {
                perror("open user_data fail\n");
        }

        while(fread(&u, sizeof(u), 1, fp))
        {
                if(strcmp(user.user_name, u.user_name) == 0)
                {
                        fseek(fp, -sizeof(u), SEEK_CUR);
                        fwrite(&user, sizeof(user), 1, fp);
                        break;
                }
        }
        fclose(fp);
}

