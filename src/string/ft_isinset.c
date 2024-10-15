/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isinset.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eoehlers <eoehlers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/19/09 17:27:57 by eoehlers      #+#    #+#                 */
/*   Updated: 2024/09/30 17:27:57 by eoehlers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief 
 * Checks if a char is in a set of chars 
 * and returns true of false based on a char
 * 
 * @param c 
 * @param set 
 * @return int32_t
 */
int32_t	ft_isinset(char const *set, char c)
{
	uint32_t	i;

	i = 0;
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
