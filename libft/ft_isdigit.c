/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:02:37 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 20:53:57 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (48 <= c && c <= 57);
}

/* #include <ctype.h>
int	main(void) {
	char test_characters[] = {'A', 'a', '5', '$', ' ', '\n'};

	int test_characters_size = sizeof(test_characters);
	for (int i = 0; i < test_characters_size; i++) {
		int character = test_characters[i];
		int result = isdigit(character);
		int result_ft = ft_isdigit(character);
		// 結果を表示
		printf("Character:'%c', isdigit:%d, ft_isdigit:%d\n", character, result,
			result_ft);
	}
	return (0);
}
 */