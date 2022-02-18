#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>

# define FORK	1
# define EAT	2
# define SLEEP	3
# define THINK	4
# define DEAD	5

typedef struct s_all_param {
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				stop_eat;
	int				philo_die;
	pthread_mutex_t	*fork;
	pthread_mutex_t	st_out;
	struct timeval	start_time;
}				t_all_param;

typedef struct s_philo {
	int				id;
	int				n_eat;
	struct timeval	last_time_eat;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_all_param		*param;
	pthread_t		thread;
}				t_philo;

int				ft_atoi(const char *nptr);
int				ft_isdigit(int c);
unsigned long	get_time(void);
int				ft_check_arg(int argc, char **argv, t_all_param *param);
int				ft_init_param(t_all_param *param, t_philo **philo);
void			ft_status_out(int status, t_philo *philo, t_all_param *param);
void			ft_eating(t_philo *philo, t_all_param *param);
void			ft_sleeping(t_philo *philo, t_all_param *param);
void			ft_thinking(t_philo *philo, t_all_param *param);
unsigned long	ft_diff_time(struct timeval time);
void			ft_wait(struct timeval time, int time_wait);
void			ft_dead(t_philo *philo, t_all_param *param);
void			ft_del_mut(t_all_param *param);
void			ft_all_detach(t_philo *philo, t_all_param *param);

#endif