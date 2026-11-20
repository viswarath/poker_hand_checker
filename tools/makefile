# $(MAKEFILE_LIST) contains data related to how the makefile was called, all separated by spaces
# $(lastword ) returns the last "word", so in a list separated by spaces, returns the last item
# $(dir ) returns the directory of the item in question
# the directory of the last item in the makefile_list is this directory
ROOT		:= $(dir $(lastword $(MAKEFILE_LIST)))../
BUILD_DIR	:= $(ROOT)build/
SRC_DIR		:= $(ROOT)src/
TEST_DIR	:= $(ROOT)test/

CC 			:= cc
CFLAGS	 	:= -W -Wall -O -I$(SRC_DIR) -MMD -MP
# -I/dir/ includes header files listed in the dir/
# -MMD, gcc makes makefiles that end in .d to target object files with the headers as a dependency
# -MP, gcc makes phony rules in those makefiles for each header, so a missing header doesn't trigger warnings

MAIN_OBJ	:= $(BUILD_DIR)main.o 
OBJECTS		:= $(BUILD_DIR)checker.o
TEST_OBJS	:= $(BUILD_DIR)test_checker.o

all: test main

# $< is the first dependency matched
# $^ is all the listed dependencies
# $@ is the target
# %.o: %.c -- the text matched with *.c is then used to name a .o file
# the rule above will apply to all .c files found

# build directory should not be included with source control
$(BUILD_DIR):		
	mkdir -p $@

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)%.o: $(TEST_DIR)%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(ROOT)main: $(OBJECTS) $(MAIN_OBJ) 
	$(CC) $^ -o $@

# to test, run makefile test
$(BUILD_DIR)run_tests: $(OBJECTS) $(TEST_OBJS) 
	$(CC) $^ -o $@ 

clean:
	rm -rf $(BUILD_DIR) $(ROOT)main

test: $(BUILD_DIR)run_tests
	$<

main: $(ROOT)main

# makefile complains if a "test", "clean", or "all" files don't exist after running
# .PHONY quiets the complaints and allows the following targets to have no dependencies too
.PHONY: all test clean main

# we need to include all the makefiles made with gcc's flag -MMD
-include $(wildcard $(BUILD_DIR)*.d)
