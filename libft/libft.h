/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 11:45:12 by agaley            #+#    #+#             */
/*   Updated: 2023/05/02 02:26:50 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>

// CHAR CHECKING

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

// NUMBER UTILS

int		ft_nbrlen(int nbr);
void	ft_nbrcpy(char *str, int nbr);

// BUFF UTILS

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

// STR UTILS

size_t	ft_strlen(const char *s);
size_t	ft_ustrlen(const unsigned char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *str, char c);

// SEARCH AND COMPARE STR

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

// SEARCH AND COMPARE MEM

void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

// TYPE CONVERSION

int		ft_atoi(const char *str);
char	*ft_itoa(int nbr);
void	ft_itob(unsigned int nbr, unsigned int size, char *binstr);
int		ft_btoi(char *bin_arr);

// MEMORY UTILS

void	*ft_calloc(size_t count, size_t size);

// FUNC UTILS

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

// PUT CHAR STR

void	ft_putendl_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(const char *s, int fd);

// PUT NUMBER

int		ft_putnbr_fd(int nb, int fd);
int		ft_putnbr_base_fd(long int nbr, const char *base, int fd);
int		ft_putunbr_base_fd(unsigned long int nbr, const char *base, int fd);

// PUT SPECIAL

int		ft_puthex_fd(unsigned long int hex, char low, int fd);
int		ft_putptr_fd(void *ptr, int fd);

// PRINT

int		ft_printf(const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);

// MATH

int		ft_pow(int nb, int power);

// STACK

typedef struct s_stack_node
{
	void				*addr;
	struct s_stack_node	*next;
}t_node;

typedef struct s_stack
{
	t_node	*head;
}t_stack;

t_stack	*stack_init(void);
void	stack_add(t_stack *stack, void *new_addr);
void	pop(t_stack *stack);
void	free_stack(t_stack *stack);
void	*malloc_n_collect(t_stack *stack, size_t size);

#endif
