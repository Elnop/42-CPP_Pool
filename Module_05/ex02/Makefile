NAME = Bureaucrat

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 # -g3

INCLUDES = Bureaucrat.h AForm.h ShrubberyCreationForm.h RobotomyRequestForm.h PresidentialPardonForm.h

FILES = main Bureaucrat AForm ShrubberyCreationForm RobotomyRequestForm PresidentialPardonForm

SRCS = $(addsuffix .cpp, $(FILES))

OBJS_DIR = .obj
OBJS = ${patsubst %.cpp, ${OBJS_DIR}/%.o, ${SRCS}}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

${OBJS_DIR}/%.o: %.cpp $(INCLUDES)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re