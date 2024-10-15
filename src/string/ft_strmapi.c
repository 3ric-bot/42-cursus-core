/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: eoehlers <eoehlers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/19/09 17:27:57 by eoehlers      #+#    #+#                 */
/*   Updated: 2024/09/30 17:27:57 by eoehlers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(uint32_t, char))
{
	char		*string;
	uint32_t	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	string = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (string == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		string[i] = f(i, s[i]);
		i++;
	}
	return (string);
}
