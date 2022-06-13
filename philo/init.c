/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:21:08 by lemarque          #+#    #+#             */
/*   Updated: 2022/06/11 19:38:54 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

static void	init_mutex(t_data **data)
{
	int	i;

	(*data)->lock_print = (pthread_mutex_t *)malloc \
		(sizeof(pthread_mutex_t) * 1);
	(*data)->check_dinner = (pthread_mutex_t *)malloc \
		(sizeof(pthread_mutex_t) * 1);
	(*data)->lock_dinner = (pthread_mutex_t *)malloc \
		(sizeof(pthread_mutex_t) * 1);
	(*data)->forks = malloc(sizeof(pthread_mutex_t) * (*data)->philos_number);
	if (!(*data)->lock_print || !(*data)->check_dinner || \
		!(*data)->lock_dinner || !(*data)->forks)
	{
		free_mem(*data);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (++i < (*data)->philos_number)
		pthread_mutex_init(&(*data)->forks[i], NULL);
	pthread_mutex_init((*data)->lock_print, NULL);
	pthread_mutex_init((*data)->check_dinner, NULL);
	pthread_mutex_init((*data)->lock_dinner, NULL);
}

void	init_data(t_data *data, int argc, char **argv)
{
	data->philos_number = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->times_must_eat = -1;
	data->timestamp = 0;
	data->dinner_is_over = 0;
	if (argc == 6)
		data->times_must_eat = ft_atoi(argv[5]);
	init_mutex(&data);
}

void	init_philosophers(t_philo **philos, t_data *data)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * data->philos_number);
	if (!philos)
		exit(1);
	i = -1;
	while (++i < data->philos_number)
	{
		(*philos)[i].lock_meals = (pthread_mutex_t *) \
				malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init((*philos)[i].lock_meals, NULL);
		(*philos)[i].id = i + 1;
		(*philos)[i].total_meals = 0;
		(*philos)[i].data = data;
		(*philos)[i].left_fork = &data->forks[i];
		(*philos)[i].right_fork = &data->forks[(i + 1) % data->philos_number];
		(*philos)[i].last_meal = 0;
	}
}
