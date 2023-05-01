/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:10:23 by agaley            #+#    #+#             */
/*   Updated: 2023/05/01 23:21:34 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "libft/libft.h"

typedef struct s_buff
{
	size_t			len;
	unsigned char	byte[33];
	unsigned char	*str;
}t_buff;

int				ft_error(int code);
t_buff			*ft_cleanbuff(t_buff *buff);
unsigned char	ft_btouchar(unsigned char *barr);
unsigned int	ft_btoi32(unsigned char *barr);

#endif
