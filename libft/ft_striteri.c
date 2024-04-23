/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:06:14 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 18:53:08 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (i < ft_strlen(s))
	{
		f(i, &s[i]);
		i++;
	}
}

/* // サンプルの関数ポインタ。文字を大文字に変換する
void convertToUpper(unsigned int index, char *c) {
    if (*c >= 'a' && *c <= 'z') {
        *c = *c - 'a' + 'A'; // アルファベット小文字を大文字に変換
    }
}

int main() {
    // テストケース1: 文字列内の各文字を大文字に変換
    char string1[] = "Hello, World!";
    ft_striteri(string1, &convertToUpper);

    printf("%s\n", string1);

    // テストケース
    char string2[] = "Hello, World!";
    ft_striteri(NULL, &convertToUpper);
    ft_striteri(string2, NULL);
    ft_striteri(NULL, NULL);

    printf("%s\n", string2);

    return 0;
}
 */