#ifndef PHILO_H
#define PHILO_H


#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>

typedef struct s_philo
{
	int id;
	int eat_count;
	long last_eat;
	pthread_t thread;
	struct s_pars *args;
	pthread_mutex_t mutex;
	pthread_mutex_t *right_fork;
	pthread_mutex_t left_fork;
} t_philo;

typedef struct s_pars
{
	int 			i;
	int 			n_philos;
	int 			t_die;
	int 			t_eat;
	int 			t_sleep;
	int 			n_eat;
	long 			start_time;
	int 			stop_simulation;
	pthread_mutex_t print_mutex;
	pthread_mutex_t simulation_mutex;
	t_philo 		*philos;
} t_pars;


int             ft_isdigit(int c);
int             ft_pars(char **av);
int				ft_atoi(char *str);
long			get_timestamp(void);
void			ft_sleep(size_t time);
void			*philo_func(void *new);
void			put_forks(t_philo *philo);
void            init_mutexes(t_pars *args);
void			take_forks(t_philo *philo);
void            ft_putchar_fd(char c, int fd);
void 			destroy_mutexes(t_pars *args);
void			*philosopher_thread(void *arg);
void            ft_putendl_fd(char *s, int fd);
void			join_philosophers(t_pars *args);
void            init_philosophers(t_pars *args);
void            ft_set_param(t_pars *args, char **av);
void            print_state(t_pars *args, int id, const char *state);

#endif
