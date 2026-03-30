/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:15:19 by ancarlos          #+#    #+#             */
/*   Updated: 2024/10/19 15:41:21 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	free_matrix(char **result, size_t j);
static int	count_str(char const *s, char const c);

static void	fill(const char *s, char **result, char c)
{
	size_t	k;
	size_t	i;
	size_t	j;

	k = 0;
	j = 0;
	while (s[k])
	{
		i = 0;
		while (s[k] && s[k] == c)
			k++;
		while (s[k] && s[k] != c)
			result[j][i++] = s[k++];
		if ((int)j < count_str(s, c))
			j++;
	}
}

static int	count_str(char const *s, char const c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	sub_malloc(const char *s, char **result, char c)
{
	const char		*s2;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	s2 = s;
	while (*s2 != '\0')
	{
		while (*s2 && *s2 == c)
			s2++;
		while (*s2 && *s2 != c)
		{
			i++;
			s2++;
		}
		result[j] = ft_calloc(i + 1, 1);
		if (!result[j])
			return (free_matrix(result, j));
		i = 0;
		j++;
	}
	return (1);
}

static int	free_matrix(char **result, size_t j)
{
	while (j > 0)
		free(result[--j]);
	free(result);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		count;

	if (!s)
		return (NULL);
	count = count_str(s, c);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (!(sub_malloc(s, result, c)))
		return (NULL);
	fill(s, result, c);
	result[count] = NULL;
	return (result);
}
/* #include <stdio.h>
int main()
{
    char *str = "--1-2--3---4----5-----42";
    char delimiter = '-';
    char **result;
	result = ft_split(str, delimiter);
	printf("%s\n", result[7]);
     if (result)
    {
        for (int i = 0; result[i]; i++)
        {
            printf("%s\n", result[6]);
            free(result[i]); // Free each substring
        }
        free(result); // Free the array of substrings
    } */
