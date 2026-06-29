CC=gcc
CFLAGS = -I./include -Wall -g -fexec-charset=UTF-8 -finput-charset=UTF-8
TARGET = employee_system
SRC = src/main.c src/auth.c src/globals.c src/employees.c src/attendance.c src/init.c src/salary.c src/utils.c src/departments_positions.c
OBJS = $(patsubst src/%.c, obj/%.o, $(SRC))

INCS=./include/*.h

all: $(TARGET)

$(TARGET):$(OBJS)
$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

obj/%.o: src/%.c $(INCS)

$(CC) $(CFLAGS) -c $< -o $@

clean:
rm -rf obj $(TARGET)

run: all
./$(TARGET)

.PHONY: all clean run distclean