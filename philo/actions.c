/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 22:33:03 by lemarque          #+#    #+#             */
/*   Updated: 2022/05/28 18:24:09 by coder            ###   ########.fr       */
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
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_lock(philo->lock_meals);
	philo->last_meal = get_time();
	pthread_mutex_unlock(philo->lock_meals);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	add_meal(philo);
}

void	philo_sleep(t_philo *philo)
{
	print_actions(SLEEP, philo);
	usleep(philo->data->time_to_sleep * 1000);
}

void	think(t_philo *philo)
{
	print_actions(THINK, philo);
	usleep(200);
}
