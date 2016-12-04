/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 11:58:21 by adippena          #+#    #+#             */
/*   Updated: 2016/12/04 13:26:05 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factrace.h"

static void		strdel(char **str)
{
	if (*str != NULL)
		free(*str);
	*str = NULL;
}

static char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len && s[i])
	{
		str[i] = s[start + i];
		i++;
	}
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char		*strnl(const char *buff, size_t *pos, size_t stop)
{
	size_t	len;
	size_t	offset;

	len = 0;
	offset = *pos;
	while (buff[*pos] != '\n' && *pos < stop)
	{
		*pos += 1;
		len++;
	}
	return (ft_strsub(buff, offset, len));
}

static char		*sjoin(char *buff, size_t *pos, size_t eob, char *temp_line)
{
	char	*temp;
	char	*temp_nl;

	temp_nl = strnl(buff, pos, eob);
	if ((temp = ft_strjoin(temp_line, temp_nl)) == NULL)
		return (NULL);
	strdel(&temp_line);
	strdel(&temp_nl);
	return (temp);
}

int				gnl(const int fd, char **line)
{
	static size_t	pos = BUFF_SIZE;
	static ssize_t	eob = BUFF_SIZE;
	static char		buff[BUFF_SIZE];
	char			*temp_line;

	temp_line = (char *)malloc(1);
	while (buff[pos] != '\n' && eob > 0)
	{
		if ((ssize_t)pos == eob)
			if (((pos = 0) == 0) &&
				((eob = read(fd, buff, BUFF_SIZE)) == -1))
				return (-1);
		if ((temp_line = sjoin(buff, &pos, eob, temp_line)) == NULL)
			return (-1);
	}
	if (ft_strlen(temp_line) == 0 && buff[pos] != '\n')
		strdel(&temp_line);
	if ((ssize_t)pos != eob)
		pos++;
	if (eob == 0 && ((pos = BUFF_SIZE) == BUFF_SIZE) &&
		((eob = BUFF_SIZE) == BUFF_SIZE))
		return (0);
	*line = temp_line;
	return (ft_strlen(*line));
}
