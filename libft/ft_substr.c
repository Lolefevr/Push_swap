/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lolefevr <lolefevr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:27:18 by lolefevr          #+#    #+#             */
/*   Updated: 2023/02/16 17:48:05 by lolefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*strcpy;
	size_t	i;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		strcpy = malloc((ft_strlen(s + start) + 1) * sizeof(char));
	else
		strcpy = (char *)malloc(sizeof(char) * len +1);
	if (!s)
		return (NULL);
	if (strcpy == NULL)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
		strcpy[i++] = s[start++];
	strcpy[i] = '\0';
	return (strcpy);
}
