# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 15:06:08 by ootsuboyosh       #+#    #+#              #
#    Updated: 2024/05/15 14:41:57 by ootsuboyosh      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c srcs/philosopher.c srcs/utils.c srcs/ft_atoi.c
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

test: 
	cd test/unit/build && cmake ../ && make && ctest -R . --verbose

.PHONY: all clean fclean re test
