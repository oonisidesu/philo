/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:11:05 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/29 12:02:01 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t;

	t = (t_list *)malloc(sizeof(t_list));
	if (t == NULL)
		return (NULL);
	t->content = content;
	t->next = NULL;
	return (t);
}

/* int main() {
    // テストケース1: 正常な動作の確認
    int data1 = 42;
    t_list *node1 = ft_lstnew(&data1);
    if (node1 != NULL) {
        printf("テストケース1: content = %d\n", *((int *)node1->content));
    } else {
        printf("テストケース1: メモリ割り当てエラー\n");
    }

    // テストケース2: content が NULL の場合
    t_list *node2 = ft_lstnew(NULL);
    if (node2 != NULL) {
        printf("テストケース2: content = %p\n", node2->content);
    } else {
        printf("テストケース2: メモリ割り当てエラー\n");
    }

    return 0;
}
 */