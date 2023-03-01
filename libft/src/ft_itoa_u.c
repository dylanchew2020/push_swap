/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchew <lchew@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 22:20:49 by lchew             #+#    #+#             */
/*   Updated: 2022/07/05 10:29:22 by lchew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_u(unsigned long n, int base, char *base_c)
{
	t_itoa	pt;

	pt.nbu = n;
	pt.a = ft_calloc(2, sizeof(char));
	if (pt.nbu == 0)
		*(pt.a) = '0';
	while (pt.nbu > 0)
	{
		pt.b = ft_substr(base_c, (pt.nbu % base), 1);
		pt.tmp = pt.a;
		pt.a = ft_strjoin(pt.b, pt.a);
		free(pt.b);
		free(pt.tmp);
		pt.nbu /= base;
	}
	return (pt.a);
}
