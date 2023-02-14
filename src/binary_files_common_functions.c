#include "binary_files_common_functions.h"

#include <stdio.h>

#include "data_struct.h"

door_state read_record_from_file(FILE *pfile, int index) {
    // Calculation of the offset at which desired entry should be located from the beginning of the file.
    int offset = index * sizeof(door_state);
    // Move the position pointer to the calculated offset from the beginning of the file.
    fseek(pfile, offset, SEEK_SET);

    // Reading a record of the specified type from a file.
    door_state record;
    fread(&record, sizeof(door_state), 1, pfile);

    // For safety reasons, we return the file position pointer to the beginning of the file.
    rewind(pfile);

    // Return read record
    return record;
}

void write_record_in_file(FILE *pfile, const door_state *record_to_write, int index) {
    // Calculation of the offset at which the required record should be located from the beginning of the
    // file.
    int offset = index * sizeof(door_state);
    // Move the position pointer to the calculated offset from the beginning of the file.
    fseek(pfile, offset, SEEK_SET);

    // Write a record of the specified type to a file.
    fwrite(record_to_write, sizeof(door_state), 1, pfile);

    // Just in case, force the I/O subsystem to write the contents of its buffer to a file right now.
    fflush(pfile);

    // For safety reasons, return the file position pointer to the beginning of the file.
    rewind(pfile);
}

void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    // Read both records from file to variables
    door_state record1 = read_record_from_file(pfile, record_index1);
    door_state record2 = read_record_from_file(pfile, record_index2);

    // Rewrite records in file
    write_record_in_file(pfile, &record1, record_index2);
    write_record_in_file(pfile, &record2, record_index1);
}

int get_file_size_in_bytes(FILE *pfile) {
    int size = 0;
    fseek(pfile, 0, SEEK_END);  // Move the position pointer to the end of the file.
    size = ftell(
        pfile);  // Read the number of bytes from the beginning of the file to the current position pointer.
    rewind(pfile);  // For safety reasons, move the position pointer back to the beginning of the file.
    return size;
}

int get_records_count_in_file(FILE *pfile) { return get_file_size_in_bytes(pfile) / sizeof(door_state); }

int output(FILE *file) {
    int is_error = 1;
    door_state tmp[1];
    while (fread(tmp, sizeof(door_state), 1, file)) {
        is_error = 0;
        printf("%d %d %d %d %d %d %d %d\n", tmp->year, tmp->month, tmp->day, tmp->hour, tmp->minute,
               tmp->second, tmp->status, tmp->code);
    }

    return is_error;
}

void sort_data(FILE *file) {
    int count = get_records_count_in_file(file);
    door_state first, second;
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - 1; j++) {
            first = read_record_from_file(file, j);
            second = read_record_from_file(file, j + 1);
            if (data_compare(first, second)) {
                swap_records_in_file(file, j, j + 1);
            }
        }
    }
}

int search_date(FILE * file, int year, int month, int day) {
    int i = -1, size = get_records_count_in_file(file);
    door_state tmp;
    for (i = 0; i < size; i++) {
        tmp = read_record_from_file(file, i);
        if (tmp.day == day && tmp.month == month && tmp.year == year) {
            break;
        }
    }
    if (i == size) i = -1;
    return i;
}