#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_wait(struct timeval time, int time_wait)
{
	unsigned long	new;

	new = ft_diff_time(time) + time_wait;
	while (ft_diff_time(time) < new)
		usleep(500);
}

unsigned long	ft_diff_time(struct timeval time)
{
	struct timeval	new;

	gettimeofday(&new, NULL);
	return ((new.tv_sec - time.tv_sec) * 1000 + (new.tv_usec - time.tv_usec)
		/ 1000);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	a;
	int	n;

	i = 0;
	a = 1;
	n = 0;
	while ((nptr[i] >= 8 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			a *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n *= 10;
		n += nptr[i] - '0';
		i++;
	}
	return (a * n);
}

void	ft_del_mut(t_all_param *param)
{
	int		i;

	i = 0;
	while (i < param->num_philo)
	{
		pthread_mutex_destroy(&param->fork[i]);
		usleep(10);
		i++;
	}
	pthread_mutex_destroy(&param->st_out);
}
