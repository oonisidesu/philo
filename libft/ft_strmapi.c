/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:58:33 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 09:25:28 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	new_str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/* char	my_function(unsigned int index, char c)
{
	(void)index;
	(void)c;
	return (c);
}

int	main(void)
{
	char const	*input_string;
	char		*result_string;

	input_string = "Hello, World!";
	result_string = ft_strmapi(NULL, NULL);
	if (result_string == NULL)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	printf("Original string: %s\n", input_string);
	printf("Modified string: %s\n", result_string);
	free(result_string);
	return (0);
}
 */