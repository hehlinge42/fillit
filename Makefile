CC = clang 
CFLAGS = -Wall -Wextra -Werror -I $(INCL)
SRCDIR = ./srcs
SRC = main.c \
	  error_handler.c \
	  parsing.c \
	  ft_math.c \
	  ft_resolve.c \
	  print.c \
	  tools.c \
	  ft_strlen.c \
	  ft_putstr.c \
	  ft_memset.c \
	  ft_bzero.c
INCL = ./includes
LIBCREATOR = $(addprefix $(LIBDIR)/, $(LIB))
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJ = $(addsuffix .o, $(basename $(SRC)))
NAME = fillit

all: $(NAME)

$(NAME): $(OBJ) $(NAME_LIB)
	@$(CC) $(CFLAGS) -o $(NAME) $^
	@echo "\n\033[38;5;1;4;1m$(NAME)\033[0m is ready to be used\n"

%.o : $(SRCDIR)/%.c  
	@echo "\033[38;5;82m$@\033[0m has been created" 
	@$(CC) -o $@ -c $? $(CFLAGS) -I $(INCL)

clean: 
	@rm -rf $(OBJ)
	@echo "\033[38;5;208m$(OBJ)\033[0m has been deleted" 

fclean: clean
	@rm -f $(NAME)
	@echo "\033[38;5;208m$(NAME)\033[0m has been deleted" 

re: fclean all

fclean_all: fclean_lib fclean

re_all: fclean_lib re

debug:
	$(CC) -g3 $(CFLAGS) -o $(NAME) $(OBJ) $(NAME_LIB)

sanitize:
	$(CC) -fsanitize=address -fno-omit-frame-pointer -g3 $(CFLAGS) -o $(NAME) $(OBJ) $(NAME_LIB) 


