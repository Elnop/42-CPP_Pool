NAME = megaphone

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

FILES = megaphone

SRCS = $(addsuffix .cpp, $(FILES))

OBJS_DIR = .obj
OBJS = ${patsubst %.cpp, ${OBJS_DIR}/%.o, ${SRCS}}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

${OBJS_DIR}/%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re makelib