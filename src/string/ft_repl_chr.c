/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_repl_chr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eoehlers <eoehlers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/19/09 17:27:57 by eoehlers      #+#    #+#                 */
/*   Updated: 2024/09/30 17:27:57 by eoehlers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_repl_chr(char *line, char cur, char new)
{
	uint32_t	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == cur)
			line[i] = new;
		i++;
	}
}
