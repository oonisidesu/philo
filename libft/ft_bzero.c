/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:13:29 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/29 14:18:36 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t size)
{
	ft_memset(s, 0, size);
}

/* int main() {
    char buffer[10] = "abcdefghij"; // 10バイトのバッファ
    char b_ft[10] = "abcdefghij"; // 10バイトのバッファ
	
	// ----------- bzero ----------- 
	printf("before bzero: ");
	for (size_t i = 0; i < sizeof(buffer); i++) {
        printf("%02x ", (unsigned char)buffer[i]);
    }
	printf("\n");
    // バッファをゼロで初期化
    bzero(buffer, sizeof(buffer));
	// そもそもコンパイルが通らない
    //bzero(NULL, 0);
	// エラーで止まる
    //bzero(NULL, 1);

    // ゼロで初期化されたバッファの内容を表示
    printf("after bzero: ");
    for (size_t i = 0; i < sizeof(buffer); i++) {
        printf("%02x ", (unsigned char)buffer[i]);
    }
    printf("\n");

	// ----------- ft_bzero -----------
	printf("before ft_bzero: ");
	for (size_t i = 0; i < sizeof(b_ft); i++) {
        printf("%02x ", (unsigned char)b_ft[i]);
    }
	printf("\n");
    // バッファをゼロで初期化
    ft_bzero(b_ft, sizeof(b_ft));
    // 本物がコンパイル通らないので気にしない
    //ft_bzero(NULL, 0);
	// NULLに0を入れようとしてエラーで止まる
    //ft_bzero(NULL, 1);

    // ゼロで初期化されたバッファの内容を表示
    printf("after ft_bzero: ");
    for (size_t i = 0; i < sizeof(b_ft); i++) {
        printf("%02x ", (unsigned char)b_ft[i]);
    }
    printf("\n");

    return 0;
}
 */