/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:29:07 by jamendoe          #+#    #+#             */
/*   Updated: 2022/11/12 18:29:09 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t			ft_strlen(const char *s);
int				ft_printf(const char *output, ...);
int				ft_print_var(va_list var, const char letter);
int				ft_pf_putchar(int c);
int				ft_pf_putstr(char *s);
int				ft_print_pointer(unsigned long long pointer);
void			ft_write_pointer(uintptr_t pointer);
int				ft_lenght_address(uintptr_t pointer);
int				ft_pf_putnbr(int n);
void			ft_write_number(int n);
int				ft_lenght_number(int number);
int				ft_print_ui_number(unsigned int number);
void			ft_write_ui_number(unsigned int number);
int				ft_lenght_ui_number(unsigned int number);
int				ft_print_numberhex(unsigned int number, char letter);
void			ft_write_numberhex(unsigned int number, char letter);
int				ft_lenght_numberhex(unsigned int number);
char			*ft_strdup(const char *s);
char			*get_next_line(int fd);
char			*ft_buffer(int fd, char *buffer);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_next_line(char *buffer);
char			*ft_new_buffer(char *buffer, char *nextbuffer, \
int i, int buffer_len);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);

#endif
