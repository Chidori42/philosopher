############################## varaibles section #######################

#Mandatory source files names.

SRCS                    =	main.c \
							ft_atoi.c \
							ft_isdigit.c \
							ft_putchar_fd.c \
							ft_putendl_fd.c \
							ft_setparam.c \
							ft_inits.c \
							ft_pars.c \
							utils.c \

#Mandatory object files name.

OBJECTS                 = $(SRCS:%c=%o)

CFLAGS                  = -Wall -Wextra -Werror -g -fsanitize=address

NAME                    = philo

############################ Rules Section ############################

all                     : $(NAME)

%.o: %.c philo.h  
	cc $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJECTS)
	cc $(CFLAGS) $(OBJECTS) -o $@

clean                   :
	rm -f *.o

fclean                  : clean
	rm -f $(NAME)

re                      : fclean all

.PHONY                  : clean