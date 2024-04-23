/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:18:35 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 20:52:53 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*
#include <ctype.h>

int	main(void) {
	char test_characters[] = {'A', 'a', '5', '$', ' ', '\n'};

	int test_characters_size = sizeof(test_characters);
	for (int i = 0; i < test_characters_size; i++) {
		int character = test_characters[i];
		int result = isalnum(character);
		int result_ft = ft_isalnum(character);
		// 結果を表示
		printf("Character:'%c', isalnum:%d, ft_isalnum:%d\n", character, result,
			result_ft);
	}
	return (0);
}
 */