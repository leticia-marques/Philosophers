/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:31:12 by lemarque          #+#    #+#             */
/*   Updated: 2022/06/11 20:13:34 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<pthread.h>//thread
# include<unistd.h>//write
# include<stdlib.h>//malloc
# include<stdio.h>//printf
# include<sys/time.h>

# define EAT 1
# define SLEEP 2
# define THINK 3
# define FORK 4
# define DIED 5

typedef struct s_data
{
	int					philos_number;
	long				time_to_die;
	int					times_must_eat;
	long				time_to_sleep;
	long				time_to_eat;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*lock_print;
	pthread_mutex_t		*check_dinner;
	pthread_mutex_t		*lock_dinner;
	long				timestamp;
	int					dinner_is_over;
}				t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		philo;
	long			last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*lock_meals;
	int				total_meals;
	t_data			*data;
}				t_philo;
//Libft
void	ft_putendl_fd(char *s, int fd);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

void	check_args(int argc, char **argv);
void	init_data(t_data *data, int argc, char **argv);
void	init_philosophers(t_philo **philos, t_data *data);
void	print_actions(int act, t_philo *philo);
void	eat(t_philo *philo);
int		check_dinner(t_philo *philo);
long	get_time(void);
int		finished_dinner(t_philo *philos);
void	philo_sleep(t_philo *philo);
void	think(t_philo *philo);
void	init_threads(t_data *data, t_philo *philos);
void	free_mem(t_data *data);
int		get_meals(t_philo *philo);
void	dinner_is_over(t_philo *philo);
long	get_last_meal(t_philo *philo);

#endif
