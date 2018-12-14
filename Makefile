CPPFLAGS = -I. -I./editor
CFLAGS = -m64 -Wall -Wextra -Wno-deprecated-declarations -g
LDLIB = -lm -lcsfml-window -lcsfml-graphics -lcsfml-system

%.o: %.c
	gcc $(CFLAGS) $(CPPFLAGS) -c $< -o $@

SRC = $(wildcard ./*.c) $(wildcard ./editor/*.c)
OBJ = $(SRC:.c=.o)

OUTPUT = my_runner

all: $(OUTPUT)

$(OUTPUT): $(OBJ)
	gcc $(CFLAGS) $(CPPFLAGS) $(OBJ) $(LDLIB) -o $(OUTPUT)

clean:
	rm -f $(OBJ) $(TESTOBJ)

fclean: clean
	rm -f $(OUTPUT) $(TEST)

re: fclean all

.PHONY: all clean fclean re
