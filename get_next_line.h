/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 19:19:29 by bsuprun           #+#    #+#             */
/*   Updated: 2018/01/22 18:17:50 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define BUFF_SIZE 250
# define CHECK_MALLOC(x) if (!x) return (-1);

int		get_next_line(const int fd, char **line);

#endif
