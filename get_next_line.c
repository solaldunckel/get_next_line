/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:16:56 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/23 22:17:49 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		handle_line(char *s[], char **line, int ret, int fd)
{
	*line = ft_substr(s[fd], 0, ft_strlen(s[fd], 1));
	if (ret == 0)
		return (FINISH);
	if (is_in_s('\n', s[fd]) >= 0)
		s[fd] = ft_substr(s[fd], is_in_s('\n', s[fd]) + 1, ft_strlen(s[fd], 0));
	else if (ft_strlen(s[fd], 1) > 0)
		s[fd] = ft_substr(s[fd], is_in_s('\0', s[fd]) + 1, ft_strlen(s[fd], 0));
	else
		return (FINISH);
	return (SUCCESS);
}

int		get_next_line(int fd, char **line)
{
	static char		*s[1024];
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	char			*tmp;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (ERROR);
	if (!s[fd] && !(s[fd] = malloc(sizeof(char *))))
		return (ERROR);
	while ((is_in_s('\n', s[fd])) < 0 && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = s[fd];
		s[fd] = ft_strjoin(s[fd], buf);
		free(tmp);
	}
	if (!handle_line(s, &*line, ret, fd))
		return (FINISH);
	return (SUCCESS);
}
