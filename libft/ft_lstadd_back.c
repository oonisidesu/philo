/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:42:32 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 20:54:29 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

/*
int	main(void) {
	// テスト用のリストを作成
	t_list *list = NULL;
	t_list *element1 = malloc(sizeof(t_list));
	element1->content = "Element 1";
	element1->next = NULL;

	// リストに要素を追加
	//ft_lstadd_back(&list, element1);
	//ft_lstadd_back(NULL, element1);
	ft_lstadd_back(&list, NULL);

	// リストの内容を表示
	printf("List after adding element 1:\n");
	t_list *current = list;
	while (current != NULL) {
		printf("%s\n", (char *)current->content);
		current = current->next;
	}

	// 新しい要素を追加
	t_list *element2 = malloc(sizeof(t_list));
	element2->content = "Element 2";
	element2->next = NULL;
	//ft_lstadd_back(&list, element2);
	ft_lstadd_back(NULL, element2);
	//ft_lstadd_back(&list, NULL);

	// リストの内容を表示
	printf("\nList after adding element 2:\n");
	current = list;
	while (current != NULL) {
		printf("%s\n", (char *)current->content);
		current = current->next;
	}

	// メモリを解放
	free(element1);
	free(element2);

	return (0);
}
 */