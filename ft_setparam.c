#include "philo.h"

void ft_set_param(t_pars *args, char **av)
{
	if (args && av)
	{
		args->n_philos = atoi(av[1]);
		args->t_die = atoi(av[2]);
		args->t_eat = atoi(av[3]);
		args->t_sleep = atoi(av[4]);
	}
}