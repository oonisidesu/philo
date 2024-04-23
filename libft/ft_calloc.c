/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 14:02:19 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/29 14:31:54 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

/* int main() {
    //size_t count = 5; // 要素数
    //size_t size = sizeof(int); // 要素のサイズ
	//size_t count = 0;
    //size_t size = 0;
	//size_t count = 1;
    //size_t size = 0;
	size_t count = 0;
    size_t size = 1;
	//size_t count = SIZE_MAX;
    //size_t size = SIZE_MAX;

    // メモリを割り当て
    int *array = (int *)calloc(count, size);
    int *array_ft = (int *)ft_calloc(count, size);

	// ----------- calloc -----------
    if (array != NULL) {
        // メモリが正しく割り当てられた場合
        // メモリ領域の内容を表示
        printf("calloc:\n");
        for (size_t i = 0; i < count; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");

        // メモリを解放
        free(array);
    } else {
        // メモリ割り当てに失敗した場合
        printf("Memory allocation failed.\n");
    }

	// ----------- ft_calloc -----------
    if (array_ft != NULL) {
        // メモリが正しく割り当てられた場合
        // メモリ領域の内容を表示
        printf("ft_calloc:\n");
        for (size_t i = 0; i < count; i++) {
            printf("%d ", array_ft[i]);
        }
        printf("\n");

        // メモリを解放
        free(array_ft);
    } else {
        // メモリ割り当てに失敗した場合
        printf("Memory allocation failed.\n");
    }

    return 0;
}
 */