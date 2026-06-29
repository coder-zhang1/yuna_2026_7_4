#include "../include/attendance.h"
#include "../include/departments_positions.h"
#include "../include/employee.h"
#include "../include/salary.h"
#include "../include/init.h"
#include "../include/globals.h"

void init()
{
  system("mkdir -p data");
  load_employees(&employee_list);
  load_positions(&position_list);
  load_departments(&department_list);
  load_attendance(&attendance_list);
  load_salary(&salary_list);
  validate_employee_relations(&employee_list);
}
