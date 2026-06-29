#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#define MAX_ATTENDANCE_EMP 200
#define MAX_NAME_LEN 32
#define MAX_ID_LEN 32

#define ATTENDANCE_FILE "data/attendance.txt"

typedef struct AttendanceRecord
{
  char employee_id[MAX_ID_LEN];
  char emppoyee_name[MAX_NAME_LEN];
  char data[20];
  char check_in[20];
  char check_out[20];
  char status[20];
  struct AttendanceRecord *next;
} AttendanceRecord;

typedef struct
{
  char emp_id[MAX_ID_LEN];
  char emp_name[MAX_NAME_LEN];
  AttendanceRecord *checkin_head;
  AttendanceRecord *overtime_head;
  AttendanceRecord *leave_head;
} AttendanceEmpIndex;

typedef struct
{
  AttendanceEmpIndex index[MAX_ATTENDANCE_EMP];
  int emp_count;
} Attendancelist;

void add_attendance(Attendancelist *list);
void query_attendance(Attendancelist *list);
void add_leave(Attendancelist *list);
void add_overtime(Attendancelist *list);
void display_all_attendacne(Attendancelist *list);
void save_attendance(Attendancelist *list);
void load_attendance(Attendancelist *list);
void free_attendance(Attendancelist *list);


#endif // ATTENDANCE_H