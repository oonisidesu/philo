/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:53:07 by yootsubo          #+#    #+#             */
/*   Updated: 2023/10/05 10:09:32 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	printf_format(char *p, int *num, va_list args)
{
	if (ft_strncmp(p, "%c", 2) == 0)
		ft_printf_c(num, args);
	else if (ft_strncmp(p, "%s", 2) == 0)
		ft_printf_s(num, args);
	else if (ft_strncmp(p, "%p", 2) == 0)
		ft_printf_p(num, args);
	else if (ft_strncmp(p, "%d", 2) == 0)
		ft_printf_d(num, args);
	else if (ft_strncmp(p, "%i", 2) == 0)
		ft_printf_i(num, args);
	else if (ft_strncmp(p, "%u", 2) == 0)
		ft_printf_u(num, args);
	else if (ft_strncmp(p, "%x", 2) == 0)
		ft_printf_x(num, args);
	else if (ft_strncmp(p, "%X", 2) == 0)
		ft_printf_xx(num, args);
	else if (ft_strncmp(p, "%%", 2) == 0)
		ft_printf_pp(num);
}

static void	printf_str(char *p, int *num)
{
	ft_putchar_fd(*p, 1);
	*num = *num + 1;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*p;
	int		num;

	va_start(args, format);
	p = (char *)format;
	num = 0;
	while (*p != '\0')
	{
		if (*p != '%')
			printf_str(p++, &num);
		else
		{
			printf_format(p, &num, args);
			p += 2;
		}
	}
	va_end(args);
	return (num);
}

/* #include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	i;
	int	j;

	// i = printf("dddd\n");
	// j = ft_printf("dddd\n");
	// printf("%d %d\n", i, j);

	// i = printf("ddd%cd %c\n", '5', '7');
	// j = ft_printf("ddd%cd %c\n", '5', '7');
	// printf("%d %d\n", i, j);

	// i = printf("ddd%sd %s\n", "abc", "eee");
	// j = ft_printf("ddd%sd %s\n", "abc", "eee");
	// printf("%d %d\n", i, j);

	// i = printf("ddd%sd %s\n", NULL, NULL);
	// j = ft_printf("ddd%sd %s\n", NULL, NULL);
	// printf("%d %d\n", i, j); 

	// i = printf("ddd%pd %p\n", "abc", "eee");
	// j = ft_printf("ddd%pd %p\n", "abc", "eee");
	// printf("%d %d\n", i, j);

	// i = printf("ddd%dd %d\n", -123, 222);
	// j = ft_printf("ddd%dd %d\n", -123, 222);
	// printf("%d %d\n", i, j);

	// i = printf("ddd%dd %d\n", INT_MAX + 1, 222);
	// j = ft_printf("ddd%dd %d\n", INT_MAX + 1, 222);
	// printf("%d %d\n", i, j);

	// i = printf("ddd%id %i\n", -123, 222);
	// j = ft_printf("ddd%id %i\n", -123, 222);
	// printf("%d %d\n", i, j);

	// i = printf("ddd%ud %u\n", 4967295, (unsigned int)4294967295);
	// j = ft_printf("ddd%ud %u\n", 4967295, (unsigned int)4294967295);
	// printf("%d %d\n", i, j);

	// i = printf("ddd%xd %x\n", 4967295, (unsigned int)4294967295);
	// j = ft_printf("ddd%xd %x\n", 4967295, (unsigned int)4294967295);
	// printf("%d %d\n", i, j);

	// i = printf("ddd%Xd %X\n", 4967295, (unsigned int)4294967295);
	// j = ft_printf("ddd%Xd %X\n", 4967295, (unsigned int)4294967295);
	// printf("%d %d\n", i, j);

	// i = printf("ddd%%d %%\n");
	// j = ft_printf("ddd%%d %%\n");
	// printf("%d %d\n", i, j);



	size_t max_size = 1844674407;
    char *max_string = (char *)malloc(max_size * sizeof(char *));
    if (max_string == NULL) {
        fprintf(stderr, "not \n");
        return 1;
    }
    for (size_t i = 0; i < max_size - 1; i++) {
        max_string[i] = 'A';
    }
    max_string[max_size - 1] = '\0';
    i = printf("%s\n", max_string);
    j = ft_printf("%s\n", max_string);
	printf("%d %d\n", i, j);
    free(max_string);

}
 */