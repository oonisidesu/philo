/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ootsuboyoshiyuki <ootsuboyoshiyuki@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:09:43 by ootsuboyosh       #+#    #+#             */
/*   Updated: 2024/05/09 19:07:03 by ootsuboyosh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// utils.h

#ifndef UTILS_H
# define UTILS_H

# include "philosopher.h"

// 時間関連のユーティリティ関数
void	get_current_time(struct timeval *tv);
long	get_time_diff(struct timeval *start, struct timeval *end);

// ログ出力関連のユーティリティ関数
void	log_philosopher_action(t_philosopher *philo, const char *action);
int		ft_atoi(const char *str);

#endif // UTILS_H
