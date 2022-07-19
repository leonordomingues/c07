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
		total += ft_strlen(str[a]);
		a++;
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
			while (d < ft_strlen(sep))
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

int main()
{
	int s = 4;
	char *st[] = {"epa ya", "se calhar",
	  	"mais ou menos", "tipo 6"};
	char *sep = ", ";
	printf("%s", ft_strjoin(s, st, sep));
	return 0;
}