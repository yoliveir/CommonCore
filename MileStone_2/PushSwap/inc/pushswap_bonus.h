/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:09:55 by yurolive          #+#    #+#             */
/*   Updated: 2024/11/14 15:20:09 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_BONUS_H
# define PUSHSWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_list
{
	int	*sa;
	int	*sb;
	int	sia;
	int	sib;
	int	argc;
	int	error;
	int	atoierror;
	int	jatoi;
}	t_list;

char	*ft_substr(char *s, int start, int len);
char	*get_next_line(int fd);
int		ft_strlen(char *s);
int		ft_atoi(const char *str, t_list *d);
int		check_same_nums(t_list *d);
int		check_args(char ***args, int *argc);
int		check_num(char *s);
void	ss(t_list *d);
void	sa(int *sa);
void	rra(t_list *d);
void	rrb(t_list *d);
void	ra(t_list *d);
void	pa(t_list *d);
void	pb(t_list *d);
void	rb(t_list *d);
void	rr(t_list *d);
void	rrr(t_list *d);
void	sb(int *sb);
void	swap(int *argv1, int *argv2);
void	ft_free(t_list *d, int print);
void	ft_checker_lines(t_list *d);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s1);
void	ft_free_split(char **split);

#endif
