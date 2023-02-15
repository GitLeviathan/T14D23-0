FLAGS = -Wall -Werror -Wextra
BUILD = ../build/

all:
	make state_sort state_search clear_state

state_sort:
	gcc $(FLAGS) state_sort.c binary_files_common_functions.c data_struct.c -o $(BUILD)Quest_1

state_search:
	gcc $(FLAGS) state_search.c binary_files_common_functions.c data_struct.c -o $(BUILD)Quest_2

clear_state:
	gcc $(FLAGS) clear_state.c binary_files_common_functions.c data_struct.c -o $(BUILD)Quest_3

clean:
	rm -rf $(BUILD)Quest_*