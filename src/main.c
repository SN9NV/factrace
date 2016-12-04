/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:54:42 by adippena          #+#    #+#             */
/*   Updated: 2016/12/04 01:42:45 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factrace.h"

static void starting_values(t_env *e)
{
	mpz_set_ui(e->w, 1);
	mpz_set_ui(e->x, 2);
	mpz_set_ui(e->y, 2);
}

static void	random_starting_values(t_env *e)
{
	mpz_t				n_1;
	mpz_t				n_3;
	gmp_randstate_t		rnd_state;

	mpz_init_set(n_3, e->n);
	mpz_sub_ui(n_3, n_3, 4);
	mpz_init_set(n_1, e->n);
	mpz_sub_ui(n_1, n_1, 1);
	gmp_randinit_default(rnd_state);
	mpz_urandomm(e->w, rnd_state, n_3);
	mpz_add_ui(e->w, e->w, 1);
	mpz_urandomm(e->x, rnd_state, n_1);
	mpz_set(e->y, e->x);
}

static void	init_env(t_env *e)
{
	mpz_init(e->n);
	mpz_init(e->w);
	mpz_init(e->x);
	mpz_init(e->y);
}

int			main(int argc, char **argv)
{
	t_env			e;
	unsigned int	retry;

	if (argc < 2)
		return(2);
	init_env(&e);
	retry = 50;
	if (argc == 3)
	{
		mpz_t	p;
		mpz_t	q;
		mpz_init_set_str(p, argv[1], 10);
		mpz_init_set_str(q, argv[2], 10);
		mpz_addmul(e.n, p, q);
	}
	else if (mpz_set_str(e.n, argv[1], 10) == -1)
		return(2);
	if (mpz_probab_prime_p(e.n, 15) > 0)
	{
		printf("%s is a prime number", mpz_get_str(NULL, 10, e.n));
		return(0);
	}
	if (mpz_divisible_ui_p(e.n, 2) != 0)
	{
		mpz_set_ui(e.x, 2);
		print_result(&e);
		return (0);
	}
	starting_values(&e);
	pollard_rho(&e);
	while(mpz_cmp(e.x, e.n) == 0 && --retry)
	{
		random_starting_values(&e);
		pollard_rho(&e);
	}
	if (!retry)
		printf("Reached retry limit %s", mpz_get_str(NULL, 10, e.n));
	else
		print_result(&e);
	return (0);
}
