/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:47:11 by adippena          #+#    #+#             */
/*   Updated: 2016/12/04 00:33:24 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "factrace.h"

static size_t	strlen(char const *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len] != '\0')
		++len;
	return (len);
}

static char		*strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*temp;

	new = (char *)malloc(strlen(s1) + strlen(s2) + 1);
	if (new == NULL)
		return (NULL);
	temp = new;
	while (*s1 != '\0')
		*temp++ = *s1++;
	while (*s2 != '\0')
		*temp++ = *s2++;
	*temp = '\0';
	return (new);
}

static char		*strjoinchar(char const *s, char c)
{
	char	*new;
	char	*temp;

	new = (char *)malloc(strlen(s) + 2);
	if (new == NULL)
		return (NULL);
	temp = new;
	while (*s != '\0')
		*temp++ = *s++;
	*temp++ = c;
	*temp = '\0';
	return (new);
}

void			print_result(t_env *e)
{
	char	*temp;
	char	*n;
	char	*factor;
	mpz_t	q;

	mpz_init(q);
	temp = mpz_get_str(NULL, 10, e->n);
	n = strjoinchar(temp, '=');
	temp = mpz_get_str(NULL, 10, e->x);
	factor = strjoinchar(temp, '*');
	temp = strjoin(n, factor);
	mpz_divexact(q, e->n, e->x);
	n = mpz_get_str(NULL, 10, q);
	factor = strjoinchar(n, '\n');
	n = strjoin(temp, factor);
	write(1, n, strlen(n));
}
