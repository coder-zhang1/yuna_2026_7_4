#ifndef SALARY_H
#define SALARY_H

#define MAX_SALARY_EMP 200
#define MAX_ID_LEN 32
#define MAX_NAME_LEN 32
#define SALARY_FILE "data/salary.txt"

typedef struct SalaryRecord
{
  char emp_id[MAX_NAME_LEN];
  char emp_name[MAX_ID_LEN];
  float base_salary;
  float bonus;
  float deduction;
  float net_salary;
  int year;
  int month;
  SalaryRecord *next;
} SalaryRecord;

typedef struct
{
  char emp_id[MAX_ID_LEN];
  char emp_name[MAX_NAME_LEN];
  SalaryRecord *head;
} SalaryEmpIndex;

typedef struct
{
  SalaryEmpIndex index[MAX_SALARY_EMP];
  int count;
} Salarylist;


void add_salary(Salarylist *list);
void query_salary(Salarylist *list);
void modify_salary(Salarylist *list);
void display_all_salary_info(Salarylist *list);
void caculate_net_salary(Salarylist *list);
void save_salary(Salarylist *list);
void load_salary(Salarylist *list);
void sync_salaries_to_employees(Salarylist *list);
void free_salary(Salarylist *list);
#endif // SALARY_H