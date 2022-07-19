/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lda-cunh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:58:11 by lda-cunh          #+#    #+#             */
/*   Updated: 2022/07/19 20:18:15 by lda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_str_total(int size, char **str, char *sep)
{
	int	a;
	int	total;

	a = 1;
	total = 0;
	while (a < size)
	{
		total += ft_strlen(str[total]);
		total++;
	}
	total += (ft_strlen(sep)) * (size - 1);
	return (total);
}

char *ft_strcpy(char *dest, int size, char **strs, char *sep)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = 0;
	b = 0;
	c = 0;
	d = 0;
	while (a < size)
	{
		while (c < ft_strlen(strs[a]))
			dest[b++] = strs[a][c++];
		if (a < size - 1)
		{
			while (d < ft_strlen(&sep[d]))
				dest[b++] = sep[d++];
		}
		a++;
		c = 0;
		d = 0;
	}
	dest[b] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*c;
	if (size == 0)
		return ((char*)malloc(sizeof(char)));//retornar uma freeable empty string
	c = (char*)malloc(ft_str_total(size, strs, sep) * sizeof(char));
	return (ft_strcpy(c, size, strs, sep));
}

#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int		main(void)
{
	int		offset;
	char	**strs;
	char	*res_str;

	strs = malloc(3 * sizeof(char *));
	if (strs == NULL)
		return (1);
	offset = 0;
	while (offset < 3)
	{
		strs[offset] = "abc";
		offset++;
	}
	res_str = ft_strjoin(3, strs, ", ");
	if (res_str == NULL)
		return (1);
	printf("res: %s\n", res_str);
	free(strs);
	free(res_str);
	return (0);
}
