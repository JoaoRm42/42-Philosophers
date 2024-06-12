/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:55:12 by marvin            #+#    #+#             */
/*   Updated: 2023/09/25 20:55:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	join(t_god *god)
{
	int	i;

	i = 0;
	while (i < god->params.nb_ph)
	{
		if (pthread_join(god->ph[i].th, NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_join(god->checks_death, NULL) != 0)
		return (0);
	return (1);
}

void	*start_dinner(t_god *god)
{
	int	i;

	i = 0;
	god->start_time = get_time();
	if (pthread_mutex_init(&god->prot, NULL) != 0)
		return (NULL);
	while (i < god->params.nb_ph)
	{
		pthread_mutex_lock(&god->prot);
		god->threads = i;
		pthread_mutex_unlock(&god->prot);
		if (pthread_create(&god->ph[i].th, NULL, &routine, (void *)god) != 0)
			return (NULL);
		usleep(1000);
		i++;
	}
	if (pthread_create(&god->checks_death, NULL,
			&death_checker, (void *)god) != 0)
		return (NULL);
	if (!join(god))
		return (NULL);
	end_dinner(god);
	return (NULL);
}

void	end_dinner(t_god *god)
{
	int	i;

	i = 0;
	while (i < god->params.nb_ph)
		pthread_mutex_destroy(&god->forks[i++]);
	pthread_mutex_destroy(&god->prot);
}
