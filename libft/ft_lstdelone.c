/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:37:03 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 10:45:45 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

/* // del 関数の定義
void custom_del(void *content) {
    free(content);
}

int main() {
    // テスト用の要素を作成
    t_list *element = malloc(sizeof(t_list));
    element->content = malloc(sizeof(int));
    *(int *)(element->content) = 42;
    element->next = NULL;

    // 要素の内容を表示
    printf("Element content before deletion: %d\n", *(int *)(element->content));

    // ft_lstdelone 関数を使用して要素を削除
    //ft_lstdelone(element, custom_del);
    ft_lstdelone(NULL, custom_del);
    ft_lstdelone(element, NULL);

    // 要素を削除した後の内容を表示（ポインタが解放されたため、内容は不正確になる可能性があります）
    printf("Element content after deletion: %d\n", *(int *)(element->content));

    return 0;
}
 */