/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:35:16 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 18:47:15 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*new_str;
	int		i;

	len = 0;
	i = 0;
	while (src[len] != '\0')
		len++;
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (i < len)
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/* int	main(void)
{
	// Test Cases
	// char str1[] = "Hello, world!";
	//char *result1 = strdup(((void *)0));
	//char *result1_ft = ft_strdup(((void *)0));
	//char *result1 = ft_strdup(str1);
	//printf("%s\n", str1);
	//printf("strdup:%s, ft_strdup:%s\n ", result1, result1_ft);
	//free(result1);
	//free(result1_ft);

	char str2[1] = "";
	char str2_ft[1] = "";
	char *result2 = strdup(str2);
	char *result2_ft = ft_strdup(str2_ft);
	// printf("%s\n", str2);
	// printf("strdup:%s, ft_strdup:%s\n ", result2, result2_ft);
	free(result2);
	free(result2_ft);

	// char *str3 = NULL;
	//char *result3 = strdup(str3);
	// char *result3_ft = ft_strdup(str3);
	// printf("%s\n", str3);
	// printf("strdup:%s, ft_strdup:%s\n ", result3, result3_ft);
	// free(result3);
	// free(result3_ft);

	return (0);
}
 */