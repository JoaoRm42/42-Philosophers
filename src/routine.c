/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/09/25 20:53:23 by marvin            #+#    #+#             */
/*   Updated: 2023/09/25 20:53:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *philo)
{
	t_god	*god;
	int		i;

	god = (t_god *)philo;
	pthread_mutex_lock(&god->prot);
	i = god->threads;
	pthread_mutex_unlock(&god->prot);
	while (1)
	{
		if (!ph_tasks(god, i) || god->params.nb_eat == god->ph[i].eat_count)
			break ;
		pthread_mutex_lock(&god->prot);
		if (god->has_died != 0)
		{
			pthread_mutex_unlock(&god->prot);
			break ;
		}
		else
			pthread_mutex_unlock(&god->prot);
	}
	return (NULL);
}
