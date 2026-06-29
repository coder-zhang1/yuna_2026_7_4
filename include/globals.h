#ifndef GLOBALS_H
#define GLOBALS_H


#define ROLE_ADMIN 1
#define ROLE_EMPLOYEE 2
#define ROLE_NONE 0

#define MENU_EXIT 0

extern int g_user_role;
extern char g_username[32];

typedef struct Employeelist Employeelist;
typedef struct Departmentlist Departmentlist;
typedef struct Positionlist Positionlist;
typedef struct Attendancelist Attendancelist;
typedef struct Salarylist Salarylist;

extern Employeelist employee_list;
extern Departmentlist department_list;
extern Positionlist position_list;
extern Attendancelist attendance_list;
extern Salarylist salary_list;

#endif // GLOBALS_H