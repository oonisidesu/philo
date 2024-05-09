NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS_DEBUG = -fsanitize=address -g3

# obj
OBJDIR = ./obj/

# include
INCLUDE_PATH = include
CFLAGS += -I$(INCLUDE_PATH)

# check
CHECK_PATH = srcs/check/
CHECK_FILES = check_args.c
CHECK_SRCS = $(addprefix $(CHECK_PATH), $(CHECK_FILES))

# error
ERROR_PATH = srcs/error/
ERROR_FILES = 
ERROR_SRCS = $(addprefix $(ERROR_PATH), $(ERROR_FILES))

# philo
PHILO_PATH = srcs/philo/
PHILO_FILES = main.c \
			philo.c \
			fork.c \
			log.c
PHILO_SRCS = $(addprefix $(PHILO_PATH), $(PHILO_FILES))

# utils
UTILS_PATH = srcs/utils/
UTILS_FILES = ft_atoi.c
UTILS_SRCS = $(addprefix $(UTILS_PATH), $(UTILS_FILES))

# object
CHECK_OBJS  = $(CHECK_SRCS:%.c=$(OBJDIR)%.o)
ERROR_OBJS  = $(ERROR_SRCS:%.c=$(OBJDIR)%.o)
PHILO_OBJS  = $(PHILO_SRCS:%.c=$(OBJDIR)%.o)
UTILS_OBJS  = $(UTILS_SRCS:%.c=$(OBJDIR)%.o)
OBJS_SET = $(CHECK_OBJS) $(ERROR_OBJS) $(PHILO_OBJS) $(UTILS_OBJS)

ifdef DEBUG_FLAG
	CFLAGS += $(CFLAGS_DEBUG)
endif

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)$(CHECK_PATH)
	mkdir -p $(OBJDIR)$(ERROR_PATH)
	mkdir -p $(OBJDIR)$(PHILO_PATH)
	mkdir -p $(OBJDIR)$(UTILS_PATH)

$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJDIR) $(OBJS_SET)
	$(CC) $(CFLAGS) $(OBJS_SET) -o $(NAME)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

debug:
	$(MAKE) all DEBUG_FLAG=1

.PHONY: all clean fclean re debug