/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:28:35 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 20:54:02 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}

/* #include <ctype.h>
int	main(void) {
	char test_characters[] = {'A', 'a', '5', '$', ' ', '\n'};

	int test_characters_size = sizeof(test_characters);
	for (int i = 0; i < test_characters_size; i++) {
		int character = test_characters[i];
		int result = isprint(character);
		int result_ft = ft_isprint(character);
		// 結果を表示
		printf("Character:'%c', isprint:%d, ft_isprint:%d\n", character, result,
			result_ft);
	}
	return (0);
}
 */