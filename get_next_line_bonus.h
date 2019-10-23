/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:17:21 by sdunckel          #+#    #+#             */
/*   Updated: 2019/10/23 22:21:50 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define SUCCESS 1
# define FINISH 0
# define ERROR -1

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>

size_t	ft_strlen(const char *s, int gnl);
int		is_in_s(char c, char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		handle_line(char *s[], char **line, int ret, int fd);
int		get_next_line(int fd, char **line);

#endif
