#include <stdio.h>
#include <stdlib.h>

#include "binary_files_common_functions.h"
#include "data_struct.h"

#define PATH_SIZE 255

int main() {
    int is_error = 0;
    char full_path[PATH_SIZE];

    scanf("%s", full_path);
    FILE* file = fopen(full_path, "r");

    if (file == NULL)
        is_error = 1;
    else {
        int year, month, day;
        is_error = date_input(&day, &month, &year);
        int index = search_date(file, year, month, day);
        if (index == -1)
            is_error = 1;
        else {
            door_state date_code = read_record_from_file(file, index);
            printf("%d", date_code.code);
        }
    }
    /*
    ПРОВЕРИТЬ НА ПОСЛЕДНИЙ ЭЛЕМЕНТ ФАЙЛА
    */
    if (is_error) printf("n/a");
    fclose(file);

    return 0;
}