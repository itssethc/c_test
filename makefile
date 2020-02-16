
CC = gcc

CFLAGS= -c -Wall -Werror -Wpedantic

TARGET = main.out

C_OBJECT_FILES := $(patsubst %.c,%.o,$(wildcard *.c))

all: $(TARGET)

run: 
	./$(TARGET)

$(TARGET): $(C_OBJECT_FILES)
	$(CC) $(C_OBJECT_FILES) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(C_OBJECT_FILES)
	rm -f $(TARGET)
