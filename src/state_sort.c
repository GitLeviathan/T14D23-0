#include <stdio.h>
#include <stdlib.h>

#include "binary_files_common_functions.h"
#include "data_struct.h"

#define PATH_SIZE 255

int main() {
    int command = 0, is_error = 0;
    char full_path[PATH_SIZE];

    scanf("%s", full_path);
    FILE* file = fopen(full_path, "r+b");

    if (file == NULL)
        is_error = 1;
    else {
        scanf("%d", &command);

        switch (command) {
            case 0: {
                is_error = output(file);
            } break;
            case 1: {
                sort_data(file);
                is_error = output(file);
            } break;
            case 2: {
                door_state object;
                if (data_input(&object)) {
                    int count = get_records_count_in_file(file);
                    write_record_in_file(file, &object, count);
                    sort_data(file);
                    is_error = output(file);
                } else
                    is_error = 1;
            } break;
            default:
                is_error = 1;
        }
    }

    if (is_error) printf("n/a");
    fclose(file);

    return 0;
}
