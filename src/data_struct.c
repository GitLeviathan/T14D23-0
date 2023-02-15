#include "data_struct.h"

#include <stdio.h>

int mini_compare(int first, int second) {
    int res = 0;
    if (first > second) res = 1;
    if (first < second) res = -1;
    return res;
}

void swap(int *one, int *two) {
    int tmp = *one;
    *one = *two;
    *two = tmp;
}

int data_compare(door_state first, door_state second) {
    int res = 0, f = 0, s = 0;

    f += mini_compare(first.year, second.year);
    if (f > s) res = 1;
    if (f == s) {
        f += mini_compare(first.month, second.month);
        if (f > s) res = 1;
    }
    if (f == s) {
        f += mini_compare(first.day, second.day);
        if (f > s) res = 1;
    }
    if (f == s) {
        f += mini_compare(first.hour, second.hour);
        if (f > s) res = 1;
    }
    if (f == s) {
        f += mini_compare(first.minute, second.minute);
        if (f > s) res = 1;
    }
    if (f == s) {
        f += mini_compare(first.second, second.second);
        if (f > s) res = 1;
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

    if (scanf("%d.%d.%d%c", &d, &m, &y, &c) == 4 && (c == '\n' || c == '\0' || c == EOF || c == ' ') &&
        d > 0 && m > 0 && y >= 0) {
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

void correct_time_frame(int *day1, int *month1, int *year1, int *day2, int *month2, int *year2) {
    int f = 0, s = 0;

    f += mini_compare(*year1, *year2);
    if (f == s) {
        f += mini_compare(*month1, *month2);
    }
    if (f == s) {
        f += mini_compare(*day1, *day2);
    }
    if (f > s) {
        swap(year1, year2);
        swap(month1, month2);
        swap(day1, day2);
    }
}
