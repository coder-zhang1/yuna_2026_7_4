#ifndef DEPARTMENTS_POSITIONS_H
#define DEPARTMENTS_POSITIONS_H

#define MAX_DEPARTMENTS 20
#define MAX_POSITIONS 50
#define MAX_NAME_LEN 32

#define DEPARTMENT_FILE "data/departments.txt"
#define POSITION_FILE "data/positions.txt"

typedef struct
{
  char dept_id[20];
  char dept_name[MAX_NAME_LEN];
  char manager[MAX_NAME_LEN];
} Department;

typedef struct
{
  char pos_id[20];
  char pos_name[MAX_NAME_LEN];
  float salary_level;
} Position;

typedef struct
{
  Department departments[MAX_DEPARTMENTS];
  int count;
} Departmentlist;

typedef struct
{
  Position positions[MAX_POSITIONS];
  int count;
} Positionlist;

void add_department(Departmentlist *list);
void delete_department(Departmentlist *list);
void modify_department(Departmentlist *list);
void query_department(Departmentlist *list);
void display_all_departments_info(Department *list);
void save_departments(Departmentlist *list);
void load_departments(Departmentlist *list);
int find_department_index_by_name(Departmentlist *list, const char *name);
int find_department_index_by_id(Departmentlist *list, const char *dept_id);
int creat_department_if_missing(Departmentlist *list, const char *name);

void add_position(Positionlist *list);
void delete_position(Positionlist *list);
void modify_position(Positionlist *list);
void query_position(Positionlist *list);
void display_all_positions_info(Positionlistlist);
void save_positions(Positionlist *list);
void load_positions(Positionlist *list);
int find_position_index_by_name(Positionlist *list, const char *name);
int find_position_index_by_id(Positionlist *list, const char *pos_id);
int creat_position_if_missing(Positionlist *list, const char *name);

#endif // DEPARTMENTS_POSITIONS_H