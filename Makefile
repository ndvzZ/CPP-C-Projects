TARGET = ./main.out
TARGET_TEST = ./main_test.out
HDRS_DIR = project/include
HDRS_DIR_TEST = test/include

SRCS = \
		project/src/main.c \
		project/src/transaction_write.c \
		project/src/person_data_write.c \
		project/src/update_record.c \
		project/src/file_openers.c \
		project/src/print.c

SRCS_TEST = \
		test/src/main.c \
		test/src/tst_read_from_file.c \
		test/src/is_equal.c \
		test/src/tst_write_to_file.c	

.PHONY: all build rebuild check test memtest clean mytest

all: clean check test memtest

$(TARGET_TEST): $(SRCS_TEST)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR_TEST) -o $(TARGET_TEST) $(CFLAGS) $(SRCS_TEST)

$(TARGET): $(SRCS)
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TARGET) $(CFLAGS) $(SRCS)

build: $(TARGET)

rebuild: clean build

check:
	./run_linters.sh

test: $(TARGET)
	./btests/run.sh $(TARGET)

memtest: $(TARGET)
	./btests/run.sh $(TARGET) --memcheck

clean:
	rm -rf $(TARGET) *.dat

mytest: $(TARGET_TEST)
	./main_test.out $(TARGET_TEST)
