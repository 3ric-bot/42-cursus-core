/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_str_occur.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: eoehlers <eoehlers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/19/09 17:27:57 by eoehlers      #+#    #+#                 */
/*   Updated: 2024/09/30 17:27:57 by eoehlers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

uint32_t	ft_str_occur(char *str, char c)
{
	uint32_t	amount;
	uint32_t	i;

	i = 0;
	amount = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			amount++;
		i++;
	}
	return (amount);
}
