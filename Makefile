CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = insearch

SRC = main.c \
      file_validation.c \
      create_database.c \
      insert_last.c \
      display_database.c \
      search.c \
      hash_function.c \
      save_database.c \
      update_database.c

OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.c inverted_Search.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

rebuild: clean $(TARGET)