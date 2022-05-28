/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:12:03 by lemarque          #+#    #+#             */
/*   Updated: 2022/05/28 18:23:54 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

static void	free_philos(t_philo *philos, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		if (philos[i].lock_meals)
		{
			pthread_mutex_destroy(philos[i].lock_meals);
			free(philos[i].lock_meals);
		}
	}
	if (philos)
		free(philos);
}

void	free_mem(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philos_number)
	{
		if (&data->forks[i])
			pthread_mutex_destroy(&data->forks[i]);
	}
	if (data->check_dinner)
	{
		pthread_mutex_destroy(data->check_dinner);
		free(data->check_dinner);
	}
	if (data->lock_print)
	{
		pthread_mutex_destroy(data->lock_print);
		free(data->lock_print);
	}
	if (data->forks)
		free(data->forks);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos;

	check_args(argc, argv);
	init_data(&data, argc, argv);
	init_philosophers(&philos, &data);
	init_threads(&data, philos);
	free_philos(philos, data.philos_number);
	free_mem(&data);
}
