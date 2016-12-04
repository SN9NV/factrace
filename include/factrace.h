/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factrun.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:00:30 by adippena          #+#    #+#             */
/*   Updated: 2016/12/04 00:19:00 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FACTRUN_H
# define FACTRUN_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <gmp.h>

typedef	struct	s_env
{
	mpz_t	w;
	mpz_t	x;
	mpz_t	y;
	mpz_t	n;
}				t_env;

void	f(t_env *e);
void	ff(t_env *e);

void	pollard_rho(t_env *e);

void	print_result(t_env *e);

#endif
