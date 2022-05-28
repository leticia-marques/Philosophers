/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:18:47 by lemarque          #+#    #+#             */
/*   Updated: 2022/05/28 18:24:27 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"
#include<stdio.h>

void	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 5 || argc > 6)
	{
		if (argc < 3)
			ft_putendl_fd("Too few arguments", 1);
		if (argc > 6)
			ft_putendl_fd("Too many arguments", 1);
		return ;
	}
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				ft_putendl_fd("Invalid arguments", 2);
				return ;
			}
		}
	}
}
