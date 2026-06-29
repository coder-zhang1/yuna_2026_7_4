#ifndef UTILS_H
#define UTILS_H

#include "../include/departments_positions.h";
#include "../include/employee.h"

typedef enum
{
  TYPE_EMP,  // employee
  TYPE_DEPT, // department
  TYPE_POS,  // position
} DataTableType;

int bin_search_arr(void *list, DataTableType type, const char *target_id);

int arr_shift_delete(void *list, DataTableType type, const char *target_id);

int arr_modify_info(void *list, DataTableType type, const char *target_id);

int arr_append_tail(void *list, DataTableType type);

#endif // UTILS_H