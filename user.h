#ifndef _USER_H_
#define _USER_H_

#include <time.h>

typedef struct
{
        char user_name[31];
        char user_pass[33];
        char user_role;          // 1 表示管理员， 2 表示普通用户
        time_t reg_time;         // 注册时间
        time_t last_login_time;  // 最近登录时间
} user_info;


extern user_info user;

void md5_encode(const void* data, int len, char result[33]);
int user_login(void);
int is_first_run(void);
int user_login_check(const char* user_name, const char* user_pass);
void updata_user_info(void);
void user_add(void);
void user_del(void);
int check_user_name(const char* user_name);
int updata_user_from_file(user_info* p);
int user_cu_updata(void);
#endif

