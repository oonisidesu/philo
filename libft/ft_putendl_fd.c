/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:34:48 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 20:56:38 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	if (write(fd, s, ft_strlen(s)) == -1)
		return ;
	if (write(fd, "\n", 1) == -1)
		return ;
}

/* #include <fcntl.h>
int	main(void) {
	// テストケース1: 標準出力に文字列と改行を出力
	char *string1 = "Hello, World!";
	ft_putendl_fd(string1, 1);

	// テストケース2: ファイルに文字列と改行を出力
	char *string2 = "Test Message";
	int file_descriptor = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR);
	if (file_descriptor == -1) {
		perror("ファイルを開けませんでした");
		return (1);
	}

	ft_putendl_fd(string2, file_descriptor);

	// ファイルを閉じる
	close(file_descriptor);

	printf("テストケース2: ファイルに文字列と改行を出力しました。\n");

	return (0);
}
 */