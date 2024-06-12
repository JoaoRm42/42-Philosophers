/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:56:24 by marvin            #+#    #+#             */
/*   Updated: 2023/09/25 20:56:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	help_forks(t_god *god, int i, int first_fork, int second_fork)
{
	if (pthread_mutex_lock(&god->forks[first_fork]) != 0)
		return (0);
	print_messages(god, i, FORK);
	if (pthread_mutex_lock(&god->forks[second_fork]) != 0)
	{
		pthread_mutex_unlock(&god->forks[first_fork]);
		return (0);
	}
	print_messages(god, i, FORK);
	print_messages(god, i, EAT);
	pthread_mutex_lock(&god->prot);
	god->ph[i].time_to_die = get_time() + god->params.time_to_die;
	pthread_mutex_unlock(&god->prot);
	usleep(god->params.time_to_eat * 1000);
	return (1);
}

int	pick_forks(t_god *god, int i)
{
	int	first_fork;
	int	second_fork;

	if (god->ph[i].left < god->ph[i].right)
	{
		first_fork = god->ph[i].left;
		second_fork = god->ph[i].right;
	}
	else
	{
		first_fork = god->ph[i].right;
		second_fork = god->ph[i].left;
	}
	if (!help_forks(god, i, first_fork, second_fork))
		return (0);
	return (1);
}

int	take_forks(t_god *god, int i)
{
	if (god->params.nb_ph != 1)
	{
		pick_forks(god, i);
		fork_release(god, i);
	}
	else
	{
		print_messages(god, 0, FORK);
		return (0);
	}
	return (1);
}

void	*fork_release(t_god *god, int i)
{
	if (pthread_mutex_unlock(&god->forks[god->ph[i].left]) != 0)
		return (NULL);
	if (pthread_mutex_unlock(&god->forks[god->ph[i].right]) != 0)
		return (NULL);
	pthread_mutex_lock(&god->prot);
	god->ph[i].eat_count++;
	pthread_mutex_unlock(&god->prot);
	return (NULL);
}
