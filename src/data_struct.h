#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H

typedef struct door_state {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
} door_state;

int data_compare(door_state, door_state);
int data_input(door_state *);
int date_input(int *, int *, int *);
int date_compare_less(door_state, int, int, int, int);
void correct_time_frame(int *, int *, int *, int *, int *, int *);

#endif