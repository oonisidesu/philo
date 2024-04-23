/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:43:17 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 09:21:36 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	s_len;
	size_t	i;
	size_t	malloc_len;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	malloc_len = len + 1;
	if (s_len < start)
		malloc_len = 1;
	if (s_len - start < len)
		malloc_len = s_len - start + 1;
	new_str = (char *)malloc(malloc_len * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (len > i && s_len > start + i)
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/* int	main(void)
{
	const char		*input_string;
	unsigned int	start;
	size_t			len;
	char			*result;

	input_string = "tripouille";
	start = 100;
	len = 1;
	result = ft_substr(input_string, start, len);
	if (result == NULL)
	{
		printf("メモリ割り当てエラー\n");
		return (1);
	}
	printf("元の文字列: %s\n", input_string);
	printf("部分文字列: %s\n", result);
	free(result);
	return (0);
}
 */