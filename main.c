
#include "philo.h"

void *monitor_thread(void *arg)
{
	int i;
	t_pars *args;

	args = (t_pars *)arg;
	while (1)
	{
		pthread_mutex_lock(&(args->simulation_mutex));
		if (args->stop_simulation == 1)
		{
			pthread_mutex_unlock(&(args->simulation_mutex));
			return (NULL);
		}
		pthread_mutex_unlock(&(args->simulation_mutex));
		i = -1;
		while (++i < args->n_philos)
		{
			pthread_mutex_lock(&(args->philos[i].mutex));
			if ((get_timestamp() - (args->philos[i].last_eat)) > (args->t_die))
			{
				print_state(args, args->philos[i].id, "died");
				args->stop_simulation = 1;
				pthread_mutex_unlock(&(args->philos[i].mutex));
				return (NULL);
			}
			pthread_mutex_unlock(&(args->philos[i].mutex));
		}
		usleep(100);
	}
	return (NULL);
}

int main(int ac, char **av)
{
	t_pars args;
	pthread_t monitor;

	if (ac == 5 || ac == 6)
	{
		ft_set_param(&args, av);
		if (ft_pars(av))
			return (1);
		init_mutexes(&args);
		init_philosophers(&args);
		pthread_create(&monitor, NULL, monitor_thread, &args);
		join_philosophers(&args);
		pthread_join(monitor, NULL);
		destroy_mutexes(&args);
		free(args.philos);
	}
	else
		printf("Check number of argiments\n");
	return (0);
}
