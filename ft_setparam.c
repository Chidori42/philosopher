#include "philo.h"

void ft_set_param(t_pars *args, char **av)
{
	if (args && av)
	{
		args->stop_simulation = 0;
		args->n_philos = ft_atoi(av[1]);
		args->t_die = ft_atoi(av[2]);
		args->t_eat = ft_atoi(av[3]);
		args->t_sleep = ft_atoi(av[4]);
		if (av[5])
			args->n_eat = ft_atoi(av[5]);
		else
			args->n_eat = -1;
	}
}