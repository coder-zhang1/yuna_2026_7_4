#ifndef UTILS_H
#define UTILS_H

#include "../include/departments_positions.h";
#include "../include/employee.h"
#include "../include/salary.h"
#include "../include/attendance.h"

int bs_employee_by_id(Employeelist *list,const const char *id);

int bs_department_by_id(Department *list,const const char *id);

int bs_position_by_id(Positionlist*list,const const char *id);

int bs_attendance_by_index(Attendancelist*list,const const char *emp_id);

int bs_salary_by_index(Salarylist*list,const const char *emp_id);



// typedef enum
// {
//   TYPE_EMP,  // employee
//   TYPE_DEPT, // department
//   TYPE_POS,  // position
// } DataTableType;

// int bin_search_arr(void *list, DataTableType type, const char *target_id);

// int arr_shift_delete(void *list, DataTableType type, const char *target_id);

// int arr_modify_info(void *list, DataTableType type, const char *target_id);

// int arr_append_tail(void *list, DataTableType type);

#endif // UTILS_H