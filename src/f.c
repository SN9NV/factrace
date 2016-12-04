/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:09:13 by adippena          #+#    #+#             */
/*   Updated: 2016/12/04 00:11:14 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factrace.h"

void	f(t_env *e)
{
	mpz_pow_ui(e->x, e->x, 2);
	mpz_add(e->x, e->x, e->w);
	mpz_mod(e->x, e->x, e->n);
}

void	ff(t_env *e)
{
	mpz_pow_ui(e->y, e->y, 2);
	mpz_add(e->y, e->y, e->w);
	mpz_mod(e->y, e->y, e->n);
	mpz_pow_ui(e->y, e->y, 2);
	mpz_add(e->y, e->y, e->w);
	mpz_mod(e->y, e->y, e->n);
}
