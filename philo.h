#ifndef PHILO_H
#define PHILO_H


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "libft/libft.h"
#include <unistd.h>
#include <pthread.h>

typedef struct s_philo
{
    int id;
    long last_eat;
    pthread_t thread;
    struct s_pars *args;
} t_philo;

typedef struct s_pars
{
    int n_philos;
    int t_die;
    int t_eat;
    int t_sleep;
    pthread_mutex_t *forks;
    pthread_mutex_t mutex;
    t_philo *philos;
} t_pars;


void			init_mutexes(t_pars *args);
void			*philo_func(void *new);
void			ft_set_param(t_pars *args, char **av);
void			*philosopher_thread(void *arg);
void			init_philosophers(t_pars *args);
void			join_philosophers(t_pars *args);
void 			destroy_mutexes(t_pars *args);
void			print_state(t_pars *args, int id, const char *state);
void			take_forks(t_philo *philo);
void			put_forks(t_philo *philo);
long			get_timestamp(void);

#endif