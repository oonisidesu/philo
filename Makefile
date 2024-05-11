# Makefile for the philosophers project

NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Define directories
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/

# Source and object files
SRCS = $(SRC_DIR)main.c \
       $(SRC_DIR)philosopher.c \
       $(SRC_DIR)utils.c \
       $(SRC_DIR)ft_atoi.c

OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Header files
HEADERS = $(INC_DIR)philo.h \
          $(INC_DIR)philosopher.h \
          $(INC_DIR)utils.h

# Compile and create objects in the object directory
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

# Main rule to make the project
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

# Rule to create the object directory
$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rule to clean object files
clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJ_DIR)

# Rule to clean everything
fclean: clean
	$(RM) $(NAME)

# Rule to re-make everything
re: fclean all

# test
test: 
	cd test/unit/build && cmake ../ && make && ctest -R . --verbose

# Phony targets
.PHONY: all clean fclean re test

