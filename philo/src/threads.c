/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 00:47:29 by lemarque          #+#    #+#             */
/*   Updated: 2022/04/18 22:32:45 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

static long long get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
static void	*call_actions(t_philo *philo)
{
	philo->last_meal = get_time();
	if (philo->id % 2 == 0)
		usleep(1);
	while (philo->data->dinner_is_over == 0)
	{
		eat(philo);
	}
}
void	init_threads(t_data *data, t_philo **philos)
{
	int	i;

	i = -1 ;
	while (++i < data->philos_number)
		pthread_create(&(*philos)[i].philo, NULL, &call_actions, &(*philos)[i]);

}
