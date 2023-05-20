/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravi-ch <dravi-ch@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:01:40 by dravi-ch          #+#    #+#             */
/*   Updated: 2023/05/10 15:21:54 by dravi-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
		i++;
	while (i > 0)
	{
		if (s[i - 1] == c)
			return ((char *)(s + i - 1));
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c);

int	main(void)
{
	char str[] = "hello world";
	char *ptr;

	ptr = ft_strrchr(str, 'l');
	if (ptr != NULL)
		printf("Last occurrence of 'l' is at position %ld\n", ptr - str);
	else
		printf("Character not found.\n");

	ptr = ft_strrchr(str, 'o');
	if (ptr != NULL)
		printf("Last occurrence of 'o' is at position %ld\n", ptr - str);
	else
		printf("Character not found.\n");

	ptr = ft_strrchr(str, 'z');
	if (ptr != NULL)
		printf("Last occurrence of 'z' is at position %ld\n", ptr - str);
	else
		printf("Character not found.\n");

	return (0);
}
*/
