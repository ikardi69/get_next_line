/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:03:53 by mteffahi          #+#    #+#             */
/*   Updated: 2024/12/29 17:37:04 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_next_line(char *buffer)
{
	char	*rem;
	int		i;
	int		j;
	
	if (!buffer)
		return (free(buffer), NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	j = ft_strlen(buffer) - i;
	rem = (char *)malloc(j + 1);
	if (!rem)
		return (free(buffer), NULL);
	j = 0;
	i++;
	while (buffer[i])
		rem[j++] = buffer[i++];
	rem[i] = '\0';
	return (free(buffer), rem);
}

char	*ft_inc(char *bf, char *buffer, int nl, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		bf[j] = buffer[j];
		j++;
	}
	if (nl)
	{
		bf[i] = '\n';
		i++;
	}
	bf[i] = '\0';
	return (bf);
}

static int	ft_nl_check(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_reading(char *buffer, char *remainder, int fd)
{
	int	rd;

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		printf("rd = %d\n", rd);
		//exit(0) ;
		if (rd <= 0)
			break ;
		buffer[rd] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		if (!remainder)
			return (free(buffer), NULL);
		if (ft_nl_check(remainder))
			break ;
	}
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buffer;

	puts("here\n");
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (remainder = NULL, free(remainder), NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (remainder = NULL, free(remainder), NULL);
	remainder = ft_reading(buffer, remainder, fd);
	free(buffer);
	buffer = remainder;
	buffer = ft_nl(buffer);
	remainder = ft_next_line(remainder);
	return (buffer);
}