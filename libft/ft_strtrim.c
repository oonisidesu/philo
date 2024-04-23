/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:32:02 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 20:19:54 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	start;
	size_t	end;
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]) != NULL)
		end--;
	len = end - start;
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1 + start, len + 1);
	return (new_str);
}

/* int main() {
	const char *original_str = "\nHello \t  Please\n Trim me !\n";
	const char *trim_set = " \n\t";

	char *trimmed_str = ft_strtrim(original_str, trim_set);

	if (trimmed_str != NULL) {
		printf("Original string: \"%s\"\n", original_str);
		printf("Trimmed string: \"%s\"\n", trimmed_str);

		// トリムされた文字列を使用した後、必ず解放する
		free(trimmed_str);
	} else {
		printf("Memory allocation failed.\n");
	}

	return (0);
} */
