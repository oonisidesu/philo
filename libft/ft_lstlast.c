/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:14:13 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 14:42:26 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/* int main() {
	t_list *lastElement;
    // リストの要素を作成
    t_list *element1 = malloc(sizeof(t_list));
    int intValue = 1;
    element1->content = &intValue;
    element1->next = NULL;

    t_list *element2 = malloc(sizeof(t_list));
    int intValue2 = 2;
    element2->content = &intValue2;
    element2->next = NULL;

    t_list *element3 = malloc(sizeof(t_list));
    int intValue3 = 3;
    element3->content = &intValue3;
    element3->next = NULL;

    // リストを構築
    t_list *list = element1;
    element1->next = element2;
    element2->next = element3;

    // テストケース: リストの最後の要素を取得
    lastElement = ft_lstlast(list);
    //lastElement = ft_lstlast(NULL);
    
    if (lastElement != NULL)
        printf("last list: %d\n", *(int *)lastElement->content);
    else
        printf("no list\n");

    // リストの解放
    free(element1);
    free(element2);
    free(element3);

    return 0;
}
 */