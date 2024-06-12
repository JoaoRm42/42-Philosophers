/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:46:30 by marvin            #+#    #+#             */
/*   Updated: 2023/09/25 20:46:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	check_av_helper(char *str, int *i)
{
	int	j;

	j = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		(*i)++;
		j++;
	}
	if (str[*i] == '\0')
	{
		if (j == 10)
		{
			if (str[(*i) - 1] == '8' || str[(*i) - 1] == '9')
				return (0);
		}
		return (1);
	}
	return (0);
}

int	check_av(char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 7 && str[i] <= 13))
	{
		if (str[i + 1] == '0')
			return (0);
		i++;
	}
	if (str[i] == '-')
		return (0);
	if (str[i] == '0' && i == 0)
		return (0);
	if (!check_av_helper(str, &i))
		return (0);
	return (1);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac != 5 && ac != 6)
		return (0);
	while (i < ac)
	{
		if (!check_av(av[i]))
			return (0);
		i++;
	}
	return (1);
}

void	*death_checker(void *philo)
{
	t_god	*god;
	int		i;

	i = 0;
	god = (t_god *) philo;
	while (1)
	{
		if (!is_philo_dead(god, i))
			break ;
		i++;
		if (i == god->params.nb_ph)
			i = 0;
	}
	return (NULL);
}
