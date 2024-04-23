/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:47:19 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 14:49:48 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t;
	t_list	*n;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	t = *lst;
	while (t != NULL)
	{
		n = t->next;
		del(t->content);
		free(t);
		t = n;
	}
	*lst = NULL;
}

/* // del 関数の定義
void custom_del(void *content) {
    free(content);
}

int main() {
    // テスト用のリストを作成
    t_list *list = NULL;

    // リストに要素を追加
    for (int i = 1; i <= 5; i++) {
        t_list *element = malloc(sizeof(t_list));
        element->content = malloc(sizeof(int));
        *(int *)(element->content) = i;
        element->next = NULL;
        ft_lstadd_back(&list, element);
    }

    // リストの内容を表示
    printf("List before clearing:\n");
    t_list *current = list;
    while (current != NULL) {
        printf("%d\n", *(int *)(current->content));
        current = current->next;
    }

    // リストをクリア
    ft_lstclear(&list, custom_del);
    ft_lstclear(&list, custom_del);
    //ft_lstclear(NULL, custom_del);
    ft_lstclear(&list, NULL);

    // リストの内容を表示（空リストになるはず）
    printf("\nList after clearing:\n");
    current = list;
    while (current != NULL) {
        printf("%d\n", *(int *)(current->content));
        current = current->next;
    }

    return 0;
}
 */