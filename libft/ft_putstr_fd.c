/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:21:31 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 20:56:44 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	if (write(fd, s, ft_strlen(s)) == -1)
		return ;
}

/* #include <fcntl.h>
int	main(void) {
	// テストケース1: 標準出力に文字列を出力
	char *string1 = "Hello, World!";
	ft_putstr_fd(string1, 1); // 1は標準出力を表すファイルディスクリプタ

	// テストケース2: ファイルに文字列を出力
	char *string2 = "Test Message";
	int file_descriptor = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR);
	if (file_descriptor == -1) {
		perror("ファイルを開けませんでした");
		return (1);
	}

	ft_putstr_fd(string2, file_descriptor);

	// ファイルを閉じる
	close(file_descriptor);

	printf("テストケース2: ファイルに文字列を出力しました。\n");

	return (0);
}
 */