/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:54:42 by adippena          #+#    #+#             */
/*   Updated: 2016/12/04 13:14:46 by adippena         ###   ########.fr       */
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
	mpz_sub_ui(n_3, n_3, 3);
	mpz_init_set(n_1, e->n);
	mpz_sub_ui(n_1, n_1, 1);
	gmp_randinit_default(rnd_state);
	mpz_urandomm(e->w, rnd_state, n_3);
	mpz_add_ui(e->w, e->w, 1);
	mpz_urandomm(e->x, rnd_state, n_1);
	mpz_set(e->y, e->x);
}

static void	init_env(t_env *e, char **line)
{
	mpz_init(e->n);
	mpz_init(e->w);
	mpz_init(e->x);
	mpz_init(e->y);
	*line = NULL;
}

void		pollard(t_env *e)
{
	size_t	retry;

	retry = 500;
	starting_values(e);
	pollard_rho(e);
	while(mpz_cmp(e->x, e->n) == 0 && --retry)
	{
		random_starting_values(e);
		pollard_rho(e);
	}
	if (retry)
		print_result(e);
}

int			main(int argc, char **argv)
{
	t_env	e;
	char	*line;

	if (argc != 2)
		return(2);
	(void)argv;
	init_env(&e, &line);
	while (gnl(STDIN_FILENO, &line) > 0)
	{
		if (mpz_set_str(e.n, line, 10) != -1 && !mpz_probab_prime_p(e.n, 50))
		{
			if (mpz_divisible_ui_p(e.n, 2) != 0)
			{
				mpz_set_ui(e.x, 2);
				print_result(&e);
			}
			else
				pollard(&e);
		}
	//	free(&line);
	//	line = NULL;
	}
	return (0);
}
