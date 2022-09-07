#include <stdio.h>
#include <time.h>
#include "company_code.h"

void now_time(void)
{
	time_t t;
        time(&t);
        struct tm* now_time = localtime(&t);
        const char* weekday[] = {"日", "一", "二", "三","四","五","六"};
        printf("\n当前系统时间为：%d年%02d月%02d日 %d:%02d:%02d 星期%s\n", now_time->tm_year + 1900, now_time->tm_mon + 1, now_time->tm_mday, now_time->tm_hour, now_time->tm_min, now_time->tm_sec, weekday[now_time->tm_wday]);

}	
