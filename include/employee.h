#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#define MAX_EMPLOYEES 100
#define MAX_NAME_LEN 32
#define MAX_ID_LEN 32
#define MAX_PHONE_LEN 32
#define MAX_EMAIL_LEN 32
#define MAX_PASSWORD_LEN 32
#define EMPLOYEES_TXT "data/employees.txt"

typedef struct
{
  char id[MAX_ID_LEN];
  char name[MAX_NAME_LEN];
  char department[MAX_NAME_LEN];
  char position[MAX_NAME_LEN];
  char phone[MAX_PHONE_LEN];
  char email[MAX_EMAIL_LEN];
  char password[MAX_PASSWORD_LEN];
  float salary;
  int age;
} Employee;

typedef struct
{
  Employee employees[MAX_EMPLOYEES];
  int count;
} Employeelist;

void add_employee(Employeelist *list);
void delete_employee(Employeelist *list);
void modify_employee(Employeelist *list);
void query_employee(Employeelist *list);
void print_employee_info(Employeelist *list, int i);
void display_all_employee_info(Employee *list);
void save_employees(Employeelist *list);
void load_employees(Employeelist *list);
void validate_employee_relations(Employeelist *list);
void password_init();
#endif // EMPLOYEE_H