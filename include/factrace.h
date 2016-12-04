/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factrun.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:00:30 by adippena          #+#    #+#             */
/*   Updated: 2016/12/04 13:17:56 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTRUN_H
# define FACTRUN_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <gmp.h>

# define BUFF_SIZE	1

typedef	struct	s_env
{
	mpz_t	w;
	mpz_t	x;
	mpz_t	y;
	mpz_t	n;
}				t_env;

void	pollard_rho(t_env *e);
void	print_result(t_env *e);
int		gnl(const int fd, char **line);

size_t	ft_strlen(char const *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
