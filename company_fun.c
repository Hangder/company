#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "company_code.h"


//保存员工信息
void save_employee(const struct employee* e)
{
	FILE* fp = fopen("employee_data", "ab");
	fwrite(e, sizeof(struct employee), 1, fp);
	fclose(fp);
}

//清空缓冲区
void clear_input(void)
{
    while(getchar() != '\n');
}
