CPPFLAGS = -I.
CFLAGS = -m64 -Wall -Wextra -Wno-deprecated-declarations -g
LDLIB = -lm -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

%.o: %.c
	gcc $(CFLAGS) $(CPPFLAGS) -c $< -o $@

SRC = $(filter-out ./main.c, $(wildcard ./*.c))
OBJ = $(SRC:.c=.o)

MAINSRC = $(wildcard ./main.c)
MAINOBJ = $(MAINSRC:.c=.o)

TESTSRC = $(wildcard ./criterion/*.c)

OUTPUT = my_runner

all: $(OUTPUT)

$(OUTPUT): $(OBJ) $(MAINOBJ)
	gcc $(CFLAGS) $(CPPFLAGS) $(OBJ) $(MAINOBJ) $(LDLIB) -o $(OUTPUT)

clean:
	rm -f $(MAINOBJ) $(OBJ) $(TESTOBJ)

fclean: clean
	rm -f $(OUTPUT) $(TEST)

re: fclean all

criterion:
	gcc $(CFLAGS) $(CPPFLAGS) -I./criterion $(SRC) $(TESTSRC) \
	$(LDLIB) -lcriterion -o a.out

.PHONY: all clean fclean re criterion
