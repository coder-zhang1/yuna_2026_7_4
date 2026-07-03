#include <stdio.h>
#include <string.h>

#include "../include/employee.h"
#include "../include/globals.h"
#include "../include/utils.h"

static void password_init(Employee *list)
{
  strcpy(list->password, "123456");
}
void load_employees(Employeelist *list)
{
  FILE *fp = fopen(EMPLOYEES_FILE, "r");
  if (fp == NULL)
  {
    display_error_message("文件打开失败");
    list->count = 0;
    return;
  }
  list->count = 0;
  while (fscanf(fp, "%s %s %s %s %s %s %s %.2f %d",
                list->employees[list->count].id,
                list->employees[list->count].name,
                list->employees[list->count].department,
                list->employees[list->count].position,
                list->employees[list->count].phone,
                list->employees[list->count].email,
                list->employees[list->count].password,
                &list->employees[list->count].salary,
                &list->employees[list->count].age) == 8)
  {
    list->count++;
    if (list->count >= MAX_EMPLOYEES)
    {
      break;
    }
  }
  fclose(fp);
}

void save_employees(Employeelist *list)
{
  FILE *fp = fopen(EMPLOYEES_FILE, "w");
  if (fp == NULL)
  {
    display_error_message("文件写入失败");
    return;
  }
  for (int i = 0; i < list->count; i++)
  {
    fprintf(fp, "%s %s %s %s %s %s %s %.2f %d\n",
            list->employees[i].id,
            list->employees[i].name,
            list->employees[i].department,
            list->employees[i].position,
            list->employees[i].phone,
            list->employees[i].email,
            list->employees[i].password,
            list->employees[i].salary,
            list->employees[i].age);
  }
  fclose(fp);
  display_success_message("文件保存成功");
}

void add_employee(Employeelist *list)
{
  if (list->count >= MAX_EMPLOYEES)
  {
    display_error_message("员工存储数量已达上限");
    return;
  }
  Employee emp;

  printf("输入员工ID：");
  scanf("%s", emp.id);

  printf("输入员工姓名：");
  scanf("%s", emp.name);

  printf("输入员工部门：");
  scanf("%s", emp.department);

  printf("输入员工岗位：");
  scanf("%s", emp.position);

  printf("输入员工移动号码：");
  scanf("%s", emp.phone);

  printf("输入员工邮件：");
  scanf("%s", emp.email);

  printf("输入员工薪资：");
  scanf("%.2f", emp.salary);

  printf("输入员工年龄：");
  scanf("%d", emp.age);

  password_init(&emp);
  list->count++;
  list->employees[list->count] = emp;
  save_employees(list);
  display_success_message("员工添加成功，请尽快修改密码");
}

void delete_employee(Employeelist *list)
{
  char id[MAX_ID_LEN];
  printf("输入员工ID：");
  scanf("%s", id);
  int idx = bs_employee_by_id(list, id);
  if (idx <= 0)
  {
    display_error_message("未找到该员工");
    return;
  }
  for (int j = idx; j < list->count - 1; j++)
  {
    list->employees[j] = list->employees[j + 1];
  }
  save_employees(list);
}