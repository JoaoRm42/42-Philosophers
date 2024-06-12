/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoped2 <joaoped2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:12:01 by marvin            #+#    #+#             */
/*   Updated: 2023/09/27 12:59:03 by joaoped2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdbool.h>

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"

typedef struct s_params
{
	int	nb_ph;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_eat;
}					t_params;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long long		time_to_die;
	int				left;
	int				right;
	pthread_t		th;
}					t_philo;

typedef struct s_table
{
	int				clean_right;
	int				clean_left;
}					t_table;

typedef struct s_god
{
	int				threads;
	int				has_died;
	long long		start_time;
	t_params		params;
	t_philo			*ph;
	t_table			clean;
	pthread_t		checks_death;
	pthread_mutex_t	*forks;
	pthread_mutex_t	prot;
}					t_god;

/* checker */
int					check_av_helper(char *str, int *i);
int					check_av(char *str);
int					check_args(int ac, char **av);
void				*death_checker(void *philo);

/* dinner */
int					join(t_god *god);
void				*start_dinner(t_god *god);
void				end_dinner(t_god *god);

/* init */
int					create_forks(t_god *god);
void				add_philos(t_god *god, int i, int j);
int					create_ph(t_god *god);
void				init(t_god *god, int ac, char **av);

/* messages */
void				*print_messages(t_god *god, int i, char *str);

/* philo */
int					take_forks(t_god *god, int i);
void				*fork_release(t_god *god, int i);
/* philo2 */
int					ph_tasks(t_god *god, int i);
int					is_philo_dead(t_god *god, int i);
void				ft_sleep(t_god *god, int i);

/* routine */
void				*routine(void *philo);

/* utils */
int					ft_atoi(const char *str);
char				ft_strcmp(char *s1, char *s2);
void				clean_structure(t_god *god);
long long			get_time(void);

#endif
