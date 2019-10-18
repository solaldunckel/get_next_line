/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:16:56 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/17 18:34:34 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		*s;
	char			buf[BUFFER_SIZE + 1];
	int				ret;
	char			*tmp;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (ERROR);
	if (!s && !(s = malloc(sizeof(char *))))
		return (ERROR);
	while ((is_in_s('\n', s)) < 0 && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = s;
		s = ft_strjoin(s, buf);
		free(tmp);
	}
	if (ret > 0 || ft_strlen_gnl(s) > 0)
		*line = ft_substr(s, 0, ft_strlen_gnl(s));
	if (is_in_s('\n', s) >= 0)
		s = ft_substr(s, is_in_s('\n', s) + 1, ft_strlen(s));
	else if (ft_strlen_gnl(s) > 0)
		s = ft_substr(s, is_in_s('\0', s) + 1, ft_strlen(s));
	else
		return (FINISH);
	return (SUCCESS);
}
