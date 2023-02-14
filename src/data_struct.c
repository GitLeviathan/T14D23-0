#include "data_struct.h"

#include <stdio.h>

/*
УБРАТЬ ELSE
*/

int data_compare(door_state first, door_state second) {
    int res = 1;
    if (first.year < second.year)
        res = 0;
    else if (first.year > second.year)
        res = 1;
    else {
        if (first.month < second.month)
            res = 0;
        else if (first.month > second.month)
            res = 1;
        else {
            if (first.day < second.day)
                res = 0;
            else if (first.day > second.day)
                res = 1;
            else {
                if (first.hour < second.hour)
                    res = 0;
                else if (first.hour > second.hour)
                    res = 1;
                else {
                    if (first.minute < second.minute)
                        res = 0;
                    else if (first.minute > second.minute)
                        res = 1;
                    else {
                        if (first.second < second.second)
                            res = 0;
                        else if (first.second > second.second)
                            res = 1;
                        else
                            res = 0;
                    }
                }
            }
        }
    }

    return res;
}

int data_input(door_state *object) {
    int res = 0, y, mo, d, h, mi, se, st, code;
    char c;

    if (scanf("%d %d %d %d %d %d %d %d%c", &y, &mo, &d, &h, &mi, &se, &st, &code, &c) == 9 &&
        (c == '\n' || c == '\0')) {
        object->year = y;
        object->month = mo;
        object->day = d;
        object->hour = h;
        object->minute = mi;
        object->second = se;
        object->status = st;
        object->code = code;
        res = 1;
    }

    return res;
}

int date_input(int *day, int *month, int *year) {
    int res = 1, d, m, y;
    char c;

    if (scanf("%d.%d.%d%c", &d, &m, &y, &c) == 4 && (c == '\n' || c == '\0' || c == EOF || c == ' ') && d > 0 && m > 0 &&
        y >= 0) {
        *day = d;
        *month = m;
        *year = y;
        res = 0;
    }
    return res;
}

int date_compare_less(door_state d1, int y, int m, int d, int flag) {
    int res = 1;
    if (flag == 0) {
        if (d1.year < y) res = 0;
        if (d1.year > y) res = 1;
        if (d1.year == y) {
            if (d1.month < m) res = 0;
            if (d1.month > m) res = 1;
            if (d1.month == m) {
                if (d1.day < d) res = 0;
                if (d1.day > d) res = 1;
                if (d1.day == d) res = 0;
            }
        }
    } else {
        if (d1.year < y) res = 1;
        if (d1.year > y) res = 0;
        if (d1.year == y) {
            if (d1.month < m) res = 1;
            if (d1.month > m) res = 0;
            if (d1.month == m) {
                if (d1.day < d) res = 1;
                if (d1.day > d) res = 0;
                if (d1.day == d) res = 0;
            }
        }
    }
    return res;
}
