/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_contains_char.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eoehlers <eoehlers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/19/09 17:27:57 by eoehlers      #+#    #+#                 */
/*   Updated: 2024/09/30 17:27:57 by eoehlers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* returns 1 if char c is found in string s. */
int	ft_str_contains_char(const char *s, const int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return (1);
		s++;
	}
	return (0);
}
