/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:14:33 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 18:55:55 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	char	*new_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	new_str = (char *)malloc((s1_len + s2_len) + 1 * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (i < s1_len + s2_len)
	{
		if (i < s1_len)
			new_str[i] = s1[i];
		else
			new_str[i] = s2[i - s1_len];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/* int	main(void)
{
	const char	*s1;
	const char	*s2;
	char		*result;

	s1 = "Hello, ";
	s2 = "World!";
	// s1 = NULL;
	// s2 = NULL;
	result = ft_strjoin(s1, s2);
	if (result == NULL)
	{
		printf("メモリ割り当てエラー\n");
		return (1);
	}
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("連結した文字列: %s\n", result);
	free(result);
	return (0);
}
 */