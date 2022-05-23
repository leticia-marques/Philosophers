/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:33:03 by lemarque          #+#    #+#             */
/*   Updated: 2022/05/23 15:52:02 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	add_meal(t_philo *philo)
{
	pthread_mutex_lock(philo->lock_meals);
	philo->total_meals++;
	pthread_mutex_unlock(philo->lock_meals);
}

void	eat(t_philo *philo)
{
	pthread_mutex_t get_last_meal;

	pthread_mutex_init(&get_last_meal, NULL);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	if (check_dinner(philo) == 1)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	print_actions(FORK, philo);
	print_actions(FORK, philo);
	print_actions(EAT, philo);
	usleep(1000);
	pthread_mutex_lock(&get_last_meal);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&get_last_meal);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	add_meal(philo);
}

void	philo_sleep(t_philo *philo)
{
	print_actions(SLEEP, philo);
	usleep(philo->data->time_to_sleep );
}

void	think(t_philo *philo)
{
	print_actions(THINK, philo);
	usleep(500);
}
