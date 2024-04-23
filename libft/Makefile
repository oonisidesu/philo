CC = CC
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRCS = 	ft_atoi.c \
		ft_calloc.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_strdup.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strnstr.c \
		ft_tolower.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_memcmp.c \
		ft_memmove.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strjoin.c \
		ft_strlcpy.c \
		ft_strncmp.c \
		ft_strrchr.c \
		ft_substr.c \
		ft_toupper.c \
		ft_strtrim.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_split.c \
		ft_pow.c \
		ft_atoi_long.c \
		ft_swap.c \
		ft_atoi_double.c

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

PRINTF = ft_printf.c \
		ft_printf_c.c \
		ft_printf_d.c \
		ft_printf_i.c \
		ft_printf_p.c \
		ft_printf_pp.c \
		ft_printf_s.c \
		ft_printf_u.c \
		ft_printf_x.c \
		ft_printf_xx.c \
		ft_putnbr_fd_f.c \
		ft_putnbr_u_fd.c \
		ft_putstr_long_fd.c \
		ft_putstr_ui_fd.c \
		ft_putstrp_fd.c

OBJDIR = ./obj/
$(OBJDIR):
	mkdir -p $(OBJDIR)
$(OBJDIR)%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

OBJS  = $(SRCS:%.c=$(OBJDIR)%.o)
BONUS_OBJS  = $(BONUS:%.c=$(OBJDIR)%.o)
PRINTF_OBJS  = $(PRINTF:%.c=$(OBJDIR)%.o)

all: $(NAME)
$(NAME): $(OBJDIR) $(OBJS) $(BONUS_OBJS) $(PRINTF_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS) $(PRINTF_OBJS)
clean:
	@rm -rf $(OBJDIR)
fclean: clean
	@rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re