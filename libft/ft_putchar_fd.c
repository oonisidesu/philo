/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:14:21 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 20:56:28 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return ;
}

/* #include <fcntl.h>
int	main(void) {
	// テストケース1: 標準出力に文字を出力
	char character1 = 'A';
	ft_putchar_fd(character1, 1); // 1は標準出力を表すファイルディスクリプタ

	// テストケース2: ファイルに文字を出力
	char character2 = 'B';
	int file_descriptor = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR);
	if (file_descriptor == -1) {
		perror("ファイルを開けませんでした");
		return (1);
	}

	ft_putchar_fd(character2, file_descriptor);

	// ファイルを閉じる
	close(file_descriptor);

	printf("テストケース2: ファイルに文字を出力しました。\n");

	return (0);
}
 */