/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 17:02:22 by ael-fagr          #+#    #+#             */
/*   Updated: 2024/06/05 17:13:58 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int ft_check_args(char **av)
{
	int i;
	int j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]))
				return (ft_putendl_fd("Error\n", 2), 1);
		}
	}
	return (0);
}

static int check_valid_num(char **av)
{
	int i;
	int num;

	i = 1;
	if (ft_atoi(av[i]) < 2)
		return (ft_putendl_fd("invalid number of philosopher", 2), 1);
	while (av[++i] && i < 5)
	{
	   num = ft_atoi(av[i]);
	   if (num < 60)
			return (ft_putendl_fd("Error\nthe Number is under 60", 2), 1);
	}
	return (0);
}

int ft_pars(char **av)
{
	if (ft_check_args(av))
		return (1);
	else if (check_valid_num(av))
		return (1);
	return (0);
}