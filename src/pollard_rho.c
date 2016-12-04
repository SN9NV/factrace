/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pollard_rho.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:29:48 by adippena          #+#    #+#             */
/*   Updated: 2016/12/04 11:55:28 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factrace.h"

static void	f(t_env *e)
{
	mpz_pow_ui(e->x, e->x, 2);
	mpz_add(e->x, e->x, e->w);
	mpz_mod(e->x, e->x, e->n);
}

static void	ff(t_env *e)
{
	mpz_pow_ui(e->y, e->y, 2);
	mpz_add(e->y, e->y, e->w);
	mpz_mod(e->y, e->y, e->n);
	mpz_pow_ui(e->y, e->y, 2);
	mpz_add(e->y, e->y, e->w);
	mpz_mod(e->y, e->y, e->n);
}

void		pollard_rho(t_env *e)
{
	mpz_t			x_y;
	mpz_t			factor;
	mpz_t			mul;
	unsigned long	steps;

	steps = 0;
	mpz_init_set_ui(factor, 1);
	mpz_init(x_y);
	mpz_init_set_ui(mul, 1);
	while (mpz_cmp_ui(factor, 1) == 0)
	{
		f(e);
		ff(e);
		mpz_set(x_y, e->x);
		mpz_sub(x_y, x_y, e->y);
		mpz_abs(x_y, x_y);
		mpz_mul(mul, mul, x_y);
		if ((steps % 100) == 0)
		{
			mpz_gcd(factor, mul, e->n);
			mpz_set_ui(mul, 1);
		}
		++steps;
	}
	mpz_set(e->x, factor);
}
