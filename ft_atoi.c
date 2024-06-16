#include "philo.h"

int     ft_atoi(char *str)
{
        int             i;
        int             sign;
        long    result;

        i = 0;
        sign = 1;
        result = 0;
        if (str[i] == '-' || str[i] == '+')
                sign = 44 - str[i++];
        while (str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10 + (str[i] - '0');
            i++;
        }
        return (result * sign);
}
