/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fagr <ael-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 02:01:44 by ael-fagr          #+#    #+#             */
/*   Updated: 2023/11/28 20:19:59 by ael-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;
	size_t	calc;

	calc = count * size;
	if (count != 0 && calc / count != size)
		return (NULL);
	tmp = (void *)malloc(calc);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, (calc));
	return (tmp);
}
