#include <stdio.h>
#include <string.h>
#include "../include/utils.h"

void display_error_message(const char *str)
{
  printf("%s", str);
}

void display_success_message(const char *str)
{
  printf("%s", str);
}

int bs_employee_by_id(Employeelist *list, const const char *id)
{
  int left = 0, right = list->count - 1;
  while (left <= right)
  {
    int mid = (left - right) / 2 + right;
    int re = strcmp(list->employees[mid].id, id);
    if (re == 0)
    {
      return mid;
    }
    else if (re < 0)
    {
      right = mid - 1;
    }
    else
    {
      left = mid + 1;
    }
  }
  return -1;
}