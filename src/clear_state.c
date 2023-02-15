#include <stdio.h>
#include <stdlib.h>

#include "binary_files_common_functions.h"
#include "data_struct.h"

#define PATH_SIZE 255

int main() {
    int is_error = 0;
    char full_path[PATH_SIZE];

    scanf("%254s", full_path);
    FILE* file = fopen(full_path, "r+b");

    if (file == NULL)
        is_error = 1;
    else {
        int year1, month1, day1, year2, month2, day2;
        if (!date_input(&day1, &month1, &year1) && !date_input(&day2, &month2, &year2)) {
            door_state date;
            FILE* buffer = tmpfile();
            int size = get_records_count_in_file(file);
            correct_time_frame(&day1, &month1, &year1, &day2, &month2, &year2);

            for (int i = 0, k = 0; i < size; i++) {
                date = read_record_from_file(file, i);
                if (date_compare_less(date, year1, month1, day1, 1)) {
                    write_record_in_file(buffer, &date, k);
                    k++;
                } else if (date_compare_less(date, year2, month2, day2, 0)) {
                    write_record_in_file(buffer, &date, k);
                    k++;
                }
            }

            fclose(file);
            file = fopen(full_path, "wb+");
            size = get_records_count_in_file(buffer);
            for (int i = 0; i < size; i++) {
                date = read_record_from_file(buffer, i);
                write_record_in_file(file, &date, i);
            }

            is_error = output(file);
            printf("\n\n%d %d", get_records_count_in_file(file), get_records_count_in_file(buffer));

            fclose(file);
            fclose(buffer);
        } else
            is_error = 1;
    }

    if (is_error) printf("n/a");
    fclose(file);

    return 0;
}