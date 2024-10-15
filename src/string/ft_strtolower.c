/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtolower.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: eoehlers <eoehlers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/19/09 17:27:57 by eoehlers      #+#    #+#                 */
/*   Updated: 2024/09/30 17:27:57 by eoehlers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* converts a string to lowercase. */
char	*ft_strtolower(char *s)
{
	const char	*orig;

	orig = s;
	while (*s != 0)
	{
		if (*s >= 'A' && *s <= 'Z')
		{
			*s += ('a' - 'A');
		}
		s++;
	}
	return ((char *)orig);
}
