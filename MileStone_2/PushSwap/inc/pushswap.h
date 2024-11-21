/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:07:09 by yurolive          #+#    #+#             */
/*   Updated: 2024/11/14 15:33:27 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>

typedef struct s_list
{
	int	*sa;
	int	*sb;
	int	*sp;
	int	sia;
	int	sib;
	int	sip;
	int	argc;
	int	percentage;
	int	lsp;
	int	control;
	int	cont;
	int	error;
	int	atoierror;
	int	jatoi;
	int	size_block;
	int	argmax;
	int	arguments;
}	t_list;

char	*ft_substr(char *s, int start, int len);
int		main(int argc, char **argv);
int		ft_strlen(char *s);
int		ft_atoi(const char *str, t_list *d);
int		check_same_nums(t_list *d);
int		check_order(t_list *d);
int		ft_isdigit(int i);
int		check_num(char *s);
int		check_args(char ***args, int *argc);
void	swap(int *argv1, int *argv2);
void	sortnum(t_list *d);
void	changenum(t_list *d);
void	ordernums(t_list *d);
void	sa(int *sa);
void	rra(t_list *d);
void	rrb(t_list *d);
void	ra(t_list *d);
void	size3(int *s, t_list *d);
void	size5(int *s, t_list *d);
void	size100(t_list *d);
void	size500(t_list *d);
void	pa(t_list *d);
void	pb(t_list *d);
void	ordernums_peq(t_list *d);
void	rb(t_list *d);
void	rr(t_list *d);
void	rrr(t_list *d);
void	ft_free(t_list *d);
void	ft_free2(t_list *d);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s1);
void	ft_free_split(char **split);

#endif
