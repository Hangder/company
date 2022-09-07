#ifndef _COMPANY_CODE_H
#define _COMPANY_CODE_H

#include <time.h>

extern int se;

struct employee
{
        int job_number;
        char name[31];
        char sex;
        char ID[29];
        char phone_number[12];
	char linkman_name[31];
	char linkman_pn[12];
	char postbox[16];
	char remarks[601];
};

void welcome(void);
void now_time(void);
void admin_menu(void);
void cu_menu(void);
void save_employee(const struct employee* e);
void input_employee(void);
void clear_input(void);
struct employee* find_employee(int job_number);
void search_employee(void);
void cu_search_employee(void); 
void delete_employee(void);
int del_employee_from_file(int job_number);
int is_employee_exist(int job_number);
int updata_employee_from_file(struct employee* p);
void updata_employee(void);
#endif
