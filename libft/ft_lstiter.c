/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:41:34 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 20:55:35 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/* // サンプルの関数ポインタ。整数を2倍にする
void	doubleInteger(void *content) {
	int *ptr = (int *)content;
	*ptr = *ptr * 2;
}

int	main(void) {
	// リストの要素を作成
	t_list *element1 = malloc(sizeof(t_list));
	int intValue = 5;
	int intValue2 = 20;
	element1->content = &intValue;
	element1->next = NULL;

	t_list *element2 = malloc(sizeof(t_list));
	element2->content = &intValue2;
	element2->next = NULL;

	// リストを作成
	t_list *list = element1;
	element1->next = element2;

	// テストケース1: 整数リストの要素を2倍にする
	ft_lstiter(list, &doubleInteger);
	printf("test1:%d, test2:%d\n", *(int *)list->content,
		*(int *)list->next->content);

	// リストの解放
	free(element1);
	free(element2);

	return (0);
} */
