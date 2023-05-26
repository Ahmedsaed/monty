APPLICATION := monty

# Directories 
BUILD_DIR := build
SRC_DIR := .
INC_DIR := .
OBJ_DIR := objects
TEST_DIR := tests

# Make flags
MAKEFLAGS += -s

# Compiler flags
CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic -std=c89 -ggdb3

# Files
SOURCE_FILES := $(wildcard $(SRC_DIR)/*.c)
HEADER_FILES := $(wildcard $(INC_DIR)/*.h)
OBJECT_FILES := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCE_FILES))
DEP_FILES := $(OBJECT_FILES:.o=.d)
EXECUTABLE := $(BUILD_DIR)/$(APPLICATION)

# Tests
INTEGRATION_TESTS_FILES = $(patsubst $(TEST_DIR)/integration/%.py,%,$(wildcard $(TEST_DIR)/integration/*.py))
UNIT_TEST_FILES = $(patsubst %.c, %, $(notdir $(wildcard $(TEST_DIR)/unit/*.c)))

all: clear_screen build run

build: setup_dirs $(EXECUTABLE)
	@$(MAKE) announce MESSAGE="Compiled successfully"

$(EXECUTABLE): $(OBJECT_FILES)
	$(CC) $(CFLAGS) -I${INC_DIR} -I${SRC_DIR} $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I${INC_DIR} -I${SRC_DIR} -MMD -c $^ -o $@

-include $(DEPS)

run:
	@./$(EXECUTABLE)

setup_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p ./$(BUILD_DIR)
	@mkdir -p ./$(TEST_DIR)
	@mkdir -p ./$(TEST_DIR/integration)
	@mkdir -p ./$(TEST_DIR/unit)

announce:
	@echo "------------------------------------------"
	@printf "|%*s%s%*s|\n" $$(expr 20 - $${#MESSAGE} / 2) "" "$(MESSAGE)" $$(expr 20 - $$(($${#MESSAGE} + 1)) / 2) ""
	@echo "------------------------------------------"

clear_screen:
	@clear

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BUILD_DIR)