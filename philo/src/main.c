/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:12:03 by lemarque          #+#    #+#             */
/*   Updated: 2022/05/19 13:55:30 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int main(int argc, char **argv)
{
	t_data data;
	t_philo *philos;
	check_args(argc, argv);
	init_data(&data, argc, argv);
	init_philosophers(&philos, &data);
	init_threads(&data, philos);
}
