/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yootsubo <yootsubo@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:02:11 by yootsubo          #+#    #+#             */
/*   Updated: 2023/09/30 12:39:35 by yootsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	first = NULL;
	while (lst != NULL)
	{
		new = ft_lstnew((*f)(lst->content));
		if (new == NULL)
		{
			while (first != NULL)
			{
				new = first->next;
				(*del)(first->content);
				free(first);
				first = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}

/* // サンプルの関数ポインタ。文字列を大文字に変換する
void *convertToUpper(void *content) {
    char *str = (char *)content;
    char *result = strdup(str);
    if (result == NULL) {
        return NULL;
    }
	char *result_p = result;
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *result_p = *str - 'a' + 'A'; // アルファベット小文字を大文字に変換
        }
        str++;
		result_p++;
    }
	*result_p = '\0';
    return result;
}

// リストの要素を解放する関数
void delElement(void *content) {
    free(content);
}

int main() {
	t_list *newList;
    // リストの要素を作成
    t_list *element1 = ft_lstnew("hello");
    t_list *element2 = ft_lstnew("world");
    t_list *element3 = ft_lstnew("123");
    
    // リストを構築
    element1->next = element2;
    element2->next = element3;

    // テストケース: 文字列リストの要素を大文字に変換する
    newList = ft_lstmap(element1, &convertToUpper, &delElement);
    //newList = ft_lstmap(NULL, &convertToUpper, &delElement);
    //newList = ft_lstmap(element1, NULL, &delElement);
    //newList = ft_lstmap(element1, &convertToUpper, NULL);
    t_list *current = newList;
    while (current != NULL) {
        printf("test: %s\n", (char *)current->content);
        current = current->next;
    }

    // リストの解放
    while (element1 != NULL) {
        t_list *next = element1->next;
        free(element1);
        element1 = next;
    }
    
    // 新しいリストの解放
    while (newList != NULL) {
        t_list *next = newList->next;
        (*delElement)(newList->content);
        free(newList);
        newList = next;
    }

    return 0;
}
 */