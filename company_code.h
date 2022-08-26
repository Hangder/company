#ifndef _COMPANY_CODE_H
#define _COMPANY_CODE_H

struct employee
{
        int job_number;
        int password;
        char name[31];
        char sex;
        long ID;
        int phone_number;
};

void main_menu(void);
void save_employee(const struct employee* e);
void input_employee(void);
void clear_input(void);
struct employee* find_employee(int job_number);
void search_employee(void);
void delete_employee();
static int del_employee_from_file(int job_number);




#endif
