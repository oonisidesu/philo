# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 15:06:08 by ootsuboyosh       #+#    #+#              #
#    Updated: 2024/05/27 15:46:13 by ootsuboyosh      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = -fsanitize=address,undefined -g

SRCS = srcs/main.c \
       srcs/philo.c \
       srcs/philo_utils.c \
       srcs/philo_routine.c \
	   srcs/philo_actions.c \
       srcs/utils.c \
       srcs/death.c \
	   srcs/ft_atoll.c
OBJS_DIR = obj
OBJS = $(SRCS:srcs/%.c=$(OBJS_DIR)/%.o)

INCLUDES = -I includes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: srcs/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	chmod +x test/integration/test_philo.sh
	./test/integration/test_philo.sh

norm:
	norminette srcs includes

debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean $(NAME)
	
.PHONY: all clean fclean re test norm debug
