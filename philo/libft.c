/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:22:50 by lemarque          #+#    #+#             */
/*   Updated: 2022/05/28 18:19:31 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	numb;
	int	i;

	sign = 1;
	numb = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if ((str[i] == '-' || str[i] == '+') || ft_isdigit(str[i]))
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
		while (ft_isdigit(str[i]))
		{
			numb = (numb * 10) + (str[i] - '0');
			i++;
		}
		return (numb * sign);
	}
	return (0);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

static int	ft_strlen(const char *str)
{
	int	s;

	s = 0;
	while (*str)
	{
		str++;
		s++;
	}
	return (s);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
