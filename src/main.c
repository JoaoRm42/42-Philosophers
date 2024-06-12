/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:11:55 by marvin            #+#    #+#             */
/*   Updated: 2023/09/27 12:25:54 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_god	*god;

	god = malloc(sizeof(t_god));
	if (!check_args(ac, av))
	{
		printf("Error\n");
		free(god);
		return (0);
	}
	init(god, ac, av);
	if (!create_ph(god) || !create_forks(god))
	{
		clean_structure(god);
		return (1);
	}
	start_dinner(god);
	clean_structure(god);
	return (0);
}
