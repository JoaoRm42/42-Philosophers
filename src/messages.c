/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:01:24 by marvin            #+#    #+#             */
/*   Updated: 2023/09/25 21:01:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*print_messages(t_god *god, int i, char *str)
{
	long long	time;

	time = get_time() - god->start_time;
	pthread_mutex_lock(&god->prot);
	if (god->has_died != 0 || god->params.nb_eat == god->ph[i].eat_count)
	{
		pthread_mutex_unlock(&god->prot);
		return (NULL);
	}
	if (ft_strcmp(str, "died") == 0)
		god->has_died = 1;
	printf("%lld %d %s\n", time, god->ph[i].id, str);
	pthread_mutex_unlock(&god->prot);
	return (NULL);
}
