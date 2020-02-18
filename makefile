
# to compile:           $ make
# to run the main file: $ make run

# to compile tests:     $ make tests
# to run tests:         $ make run-tests

# to debug:             $ make run-debug
# to debug the tests:   $ make run-debug-tests

# to clean:             $ make clean

C_COMPILER = gcc

DEBUGGER = gdb

C_FLAGS= -c -Wall -Wextra -Wpedantic $(DEBUG_FLAGS) -I$(API_DIR)
DEBUG_FLAGS = -g

SRC_DIR  = ./src/
API_DIR  = ./include/
BIN_DIR  = ./bin/
TEST_DIR = ./test/
TEST_LIB_DIR = $(TEST_DIR)c_test_lib/


TARGET = $(BIN_DIR)main.out

TEST_TARGET = $(BIN_DIR)test.out

MAIN_C_FILE = $(SRC_DIR)main.c

MAIN_C_OBJECT_FILE = $(BIN_DIR)main.o

C_OBJECT_FILES := $(patsubst $(SRC_DIR)%.c,$(BIN_DIR)%.o,$(wildcard $(SRC_DIR)*.c))

C_TEST_OBJECT_FILES := $(patsubst $(TEST_DIR)%.c,$(BIN_DIR)%.o,$(wildcard $(TEST_DIR)*.c))
C_TEST_OBJECT_FILES += $(patsubst $(TEST_LIB_DIR)%.c,$(BIN_DIR)%.o,$(wildcard $(TEST_LIB_DIR)*.c))
C_TEST_OBJECT_FILES += $(C_OBJECT_FILES)
C_TEST_OBJECT_FILES := $(filter-out $(MAIN_C_OBJECT_FILE), $(C_TEST_OBJECT_FILES))

$(BIN_DIR)%.o: $(SRC_DIR)%.c
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

$(BIN_DIR)%.o: $(TEST_DIR)%.c
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

$(BIN_DIR)%.o: $(TEST_LIB_DIR)%.c
	$(C_COMPILER) $(C_FLAGS) -c $< -o $@

$(TARGET): $(C_OBJECT_FILES)
	$(C_COMPILER) $(C_OBJECT_FILES) -o $(TARGET)

$(TEST_TARGET): $(BIN_DIR) $(C_TEST_OBJECT_FILES)
	$(C_COMPILER) $(C_TEST_OBJECT_FILES) -o $(TEST_TARGET)

$(BIN_DIR):
	mkdir $@

all: $(TARGET)	

tests: $(TEST_TARGET)

run: 
	$(TARGET)

run-tests:
	$(TEST_TARGET)

run-debug:
	$(DEBUGGER) $(TARGET)

run-debug-tests:
	$(DEBUGGER) $(TEST_TARGET)

clean:
	rm -f $(BIN_DIR)*.o
	rm -f $(BIN_DIR)*.out
