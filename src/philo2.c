/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:05:33 by joaoped2          #+#    #+#             */
/*   Updated: 2023/09/27 14:44:48 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ph_tasks(t_god *god, int i)
{
	if (!take_forks(god, i))
		return (0);
	if (god->params.nb_eat != god->ph[i].eat_count)
	{
		ft_sleep(god, i);
		print_messages(god, i, THINK);
	}
	return (1);
}

int	is_philo_dead(t_god *god, int i)
{
	pthread_mutex_lock(&god->prot);
	if (get_time() > god->ph[i].time_to_die)
	{
		pthread_mutex_unlock(&god->prot);
		print_messages (god, i, "died");
		return (0);
	}
	else
		pthread_mutex_unlock(&god->prot);
	return (1);
}

void	ft_sleep(t_god *god, int i)
{
	print_messages(god, i, SLEEP);
	usleep(god->params.time_to_sleep * 1000);
}
