/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:10:23 by agaley            #+#    #+#             */
/*   Updated: 2023/05/02 02:01:10 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft/libft.h"

typedef struct s_buff
{
	size_t			len;
	size_t			cur;
	char			byte[33];
	unsigned char	*str;
}t_buff;

int		ft_error(int code);
t_buff	*ft_cleanbuff(t_buff *buff);
void	clean_byte(char *byte, size_t bits);
void	receive_byte(char *byte, int signum);
void	set_length(t_buff *buff, int signum);

#endif
