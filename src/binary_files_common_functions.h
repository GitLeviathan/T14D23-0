#ifndef BINARY_FILES_COMMON_FUNCTIONS_H
#define BINARY_FILES_COMMON_FUNCTIONS_H

#include <stdio.h>

#include "data_struct.h"

door_state read_record_from_file(FILE *pfile, int index);
void write_record_in_file(FILE *pfile, const door_state *record_to_write, int index);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);
int output(FILE *);
void sort_data(FILE *file);
int search_date(FILE * file, int year, int month, int day);
#endif