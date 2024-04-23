/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:25:53 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 20:53:48 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

/* #include <ctype.h>
int	main(void) {
	char test_characters[] = {'A', 'a', '5', '$', ' ', '\n'};

	int test_characters_size = sizeof(test_characters);
	for (int i = 0; i < test_characters_size; i++) {
		int character = test_characters[i];
		int result = isascii(character);
		int result_ft = ft_isascii(character);
		// 結果を表示
		printf("Character:'%c', isascii:%d, ft_isascii:%d\n", character, result,
			result_ft);
	}
	return (0);
}
 */