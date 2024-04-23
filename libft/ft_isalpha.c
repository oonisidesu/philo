/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:16:19 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 20:53:27 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	return (65 <= c && c <= 90);
}

static int	ft_islower(int c)
{
	return (97 <= c && c <= 122);
}

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}

/*
#include <ctype.h>

int	main(void) {
	char test_characters[] = {'A', 'a', '5', '$', ' ', '\n'};

	int test_characters_size = sizeof(test_characters);
	for (int i = 0; i < test_characters_size; i++) {
		int character = test_characters[i];
		int result = isalpha(character);
		int result_ft = ft_isalpha(character);
		// 結果を表示
		printf("Character:'%c', isalpha:%d, ft_isalpha:%d\n", character, result,
			result_ft);
	}
	return (0);
}
 */