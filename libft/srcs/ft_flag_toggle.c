/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_toggle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/02 20:37:58 by igomez            #+#    #+#             */
/*   Updated: 2015/02/04 16:33:45 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_flag_toggle(int *flag, int mask)
{
	return (*flag ^= mask);
}
