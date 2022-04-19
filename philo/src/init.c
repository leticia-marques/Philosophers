/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:21:08 by lemarque          #+#    #+#             */
/*   Updated: 2022/04/18 21:54:42 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

static void	init_mutex(t_data **data)
{
	int	i;

	(*data)->stop_dinner = malloc(sizeof(pthread_mutex_t) * 1);
	(*data)->lock_print = malloc(sizeof(pthread_mutex_t) * 1);
	if (!(*data)->lock_print || (*data)->stop_dinner)
	{
		printf("Malloc failed.\n");
	}
	(*data)->forks = malloc(sizeof(pthread_mutex_t) * (*data)->philos_number);
	i = -1;
	while (++i < (*data)->philos_number)
		pthread_mutex_init(&(*data)->forks[i], NULL);
}

void	init_data(t_data *data, int argc, char **argv)
{
	data->philos_number = ft_atoi(argv[1]);
	data->is_alone = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->times_must_eat = 0;
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
	(*philos)[data->philos_number -1].left_fork = &data->forks[0];
	while (++i < data->philos_number)
	{
		(*philos)[i].lock_meals = (pthread_mutex_t *) \
				malloc(sizeof(pthread_mutex_t));
		(*philos)[i].is_alive = (pthread_mutex_t *) \
				malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init((*philos)[i].lock_meals, NULL);
		pthread_mutex_init((*philos)[i].is_alive, NULL);
		(*philos)[i].id = i + 1;
		(*philos)[i].total_meals = 0;
		(*philos)[i].data = data;
		(*philos)[i].left_fork = &data->forks[i];
		(*philos)[i].right_fork = &data->forks[i+1];
		(*philos)[i].last_meal = 0;
	}
}
