/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque < lemarque@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 01:21:08 by lemarque          #+#    #+#             */
/*   Updated: 2022/04/13 23:34:35 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	init_data(t_data *data, int argc, int **argv)
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
	init_forks(&data);
}

void	init_mutex(t_data **data)
{
	int	i;


	(*data)->stop_dinner = malloc(sizeof(pthread_mutex_t) * 1);
	(*data)->lock_print = malloc(sizeof(pthread_mutex_t) * 1);
	if (!(*data)->lock_print || (*data)->stop_dinner)
	{
		printf("Malloc failed.\n");
	}
	(*data)->forks = malloc(sizeof(pthread_mutex_t) * (*data)->philos_number)
	i = -1;
	while (++i < (*data)->philos_number)
		pthread_mutex_init(&(*data)->forks[i], NULL);
}
