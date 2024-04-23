/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:12:27 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/29 15:12:24 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isupper(int c)
{
	return (65 <= c && c <= 90);
}

int	ft_tolower(int c)
{
	int	result;

	result = c;
	if (ft_isupper(c))
		result += 32;
	return (result);
}

/* int	main(void)
{
	char	uppercase;
	char	lowercase;

	uppercase = 'A';
	printf("--orignal--\n");
	lowercase = tolower(uppercase);
	printf("大文字: %c\n", uppercase);
	printf("小文字: %c\n", lowercase);
	printf("--ft--\n");
	lowercase = ft_tolower(uppercase);
	printf("大文字: %c\n", uppercase);
	printf("小文字: %c\n", lowercase);
	return (0);
}
 */