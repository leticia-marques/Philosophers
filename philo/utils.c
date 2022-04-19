/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 23:16:57 by lemarque          #+#    #+#             */
/*   Updated: 2022/04/18 23:42:08 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	print_actions(int act)
{
	if (act == EAT)
		printf("Comeu");
	if (act == SLEEP)
		printf("Dormiu");
	if (act == THINK)
		printf("PENSOU");
	if (act == FORK)
		printf("EPGOU UM GARFO");
	if (act == DIED)
		printf("MORREU :(");
}
