/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:01:42 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/29 15:12:02 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_islower(int c)
{
	return (97 <= c && c <= 122);
}

int	ft_toupper(int c)
{
	int	result;

	result = c;
	if (ft_islower(c))
		result -= 32;
	return (result);
}

/* int	main(void)
{
	char	uppercase;
	char	lowercase;

	lowercase = 'a';
	printf("--orignal--\n");
	uppercase = ft_toupper(lowercase);
	printf("小文字: %c\n", lowercase);
	printf("大文字: %c\n", uppercase);
	printf("--ft--\n");
	uppercase = ft_toupper(lowercase);
	printf("小文字: %c\n", lowercase);
	printf("大文字: %c\n", uppercase);
	return (0);
}
 */