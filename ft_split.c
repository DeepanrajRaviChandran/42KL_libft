/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dravi-ch <dravi-ch@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 14:40:44 by dravi-ch          #+#    #+#             */
/*   Updated: 2023/05/19 15:53:35 by dravi-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_substring(char const *str, char delimiter)
{
	int	word;
	int	is_word;

	while (*str)
	{
		if (*str == delimiter)
			is_word = 0;
		else if (is_word == 0)
		{
			is_word = 1;
			word++;
		}
		str++;
	}
	return (word);
}

static int	free_string(char **str, int i)
{
	while (--i >= 0)
		free(str[i]);
	free(str);
	return (0);
}

static int	str_mem_alloc(char **str, int i, int cha)
{
	str[i] = malloc(sizeof(char) * (cha + 1));
	if (!str[i])
		return (free_string(str, i));
	return (1);
}

static char	**initmem(char const *s, char c)
{
	int		cha;
	int		i;
	char	**str;

	str = ft_calloc((count_substring(s, c) + 1), sizeof(char *));
	if (!str)
		return (NULL);
	cha = 0;
	i = 0;
	while (*s)
	{
		if (*s++ != c)
			cha++;
		else
		{
			if (cha > 0)
				if (!str_mem_alloc(str, i++, cha))
					return (NULL);
			cha = 0;
		}
	}
	if (cha > 0)
		if (!str_mem_alloc(str, i++, cha))
			return (NULL);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		start;

	if (!s || s[0] == '\0')
		return (ft_calloc(1, sizeof(char *)));
	res = initmem(s, c);
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	start = 0;
	while (s[++i])
	{
		if (s[i] == c)
		{
			if ((i - start) > 0)
				ft_strlcpy(res[j++], &s[start], (i - start) + 1);
			start = i + 1;
		}
	}
	if ((i - start) > 0)
		ft_strlcpy(res[j], &s[start], (i - start) + 1);
	return (res);
}
/*
#include <stdio.h>

int main(void)
{
    char const *s = "Hello    world  this  is a test";
    char c = ' ';

    // Call ft_split and store the result
    char **result = ft_split(s, c);

    // Check if ft_split succeeded (result is not NULL)
    if (result == NULL)
    {
        printf("ft_split failed to allocate memory.\n");
        return 1; // Return an error code
    }

    // Print the resulting array of strings
    for (int i = 0; result[i] != NULL; i++)
    {
        printf("%s\n", result[i]);
    }

    // Free the memory allocated by ft_split
    for (int i = 0; result[i] != NULL; i++)
    {
        free(result[i]);
    }
    free(result);

    return 0; // Return success
}
*/
