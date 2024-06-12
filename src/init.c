/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:57:04 by marvin            #+#    #+#             */
/*   Updated: 2023/09/25 20:57:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	create_forks(t_god *god)
{
	int	i;

	i = 0;
	god->forks = malloc(sizeof(pthread_mutex_t) * god->params.nb_ph);
	if (!god->forks)
		return (0);
	while (i < god->params.nb_ph)
	{
		if (pthread_mutex_init(&god->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

void	add_philos(t_god *god, int i, int j)
{
	god->ph[i].id = i + 1;
	god->ph[i].eat_count = 0;
	god->ph[i].time_to_die = get_time() + god->params.time_to_die;
	god->ph[i].left = i;
	god->ph[i].right = j;
}

int	create_ph(t_god *god)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	god->ph = malloc(sizeof(t_philo) * god->params.nb_ph);
	if (!(god->ph))
		return (0);
	while (j < god->params.nb_ph)
	{
		add_philos(god, i, j);
		i++;
		j++;
	}
	j = 0;
	add_philos(god, i, j);
	return (1);
}

void	init(t_god *god, int ac, char **av)
{
	god->params.nb_ph = ft_atoi(av[1]);
	god->params.time_to_die = ft_atoi(av[2]);
	god->params.time_to_eat = ft_atoi(av[3]);
	god->params.time_to_sleep = ft_atoi(av[4]);
	god->has_died = 0;
	if (ac == 6)
		god->params.nb_eat = ft_atoi(av[5]);
	else
		god->params.nb_eat = -1;
	god->clean.clean_right = 0;
	god->clean.clean_left = 0;
}
