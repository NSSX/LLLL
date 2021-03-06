/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 13:00:28 by igomez            #+#    #+#             */
/*   Updated: 2016/06/18 15:06:53 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	(*g_intersect[OBJ_NUMBER])(t_ray *, t_obj *) =
{
	&ray_intersect_sphere,
	&ray_intersect_plane,
	&ray_intersect_cylinder,
	&ray_intersect_cone
};

static int	ray_iscloser(t_ray *ray_old, t_ray *ray_new)
{
	if (!ray_old->obj)
		return (1);
	if (ray_new->dist > 0 && ray_new->dist < ray_old->dist)
		return (1);
	return (0);
}

static int	ray_intersect_obj(t_ray *ray, t_obj *obj)
{
	if ((uint32_t)obj->param.type > OBJ_NUMBER)
		return (0);
	/*
		g_intersect[SPHERE](ray, obj);
		g_intersect[PLANE](ray, obj);
		g_intersect[CYLINDER](ray, obj);
		g_intersect[CONE](ray, obj);
	*/
	return (g_intersect[obj->param.type](ray, obj));
}

int			ray_intersect(t_ray *ray, t_env *e)
{
	t_list	*lst;
	t_ray	tmp;

	lst = e->scene->obj;
	while (lst)
	{
		tmp = *ray;
		ray_setup_obj(&tmp, lst->content);
		ray_intersect_obj(&tmp, lst->content);
		if (tmp.obj && ray_iscloser(ray, &tmp))
		{
			ray->obj = tmp.obj;
			ray->dist = tmp.dist;
			ray->intersection = tmp.intersection;
			ray->normal = tmp.normal;
		}
		lst = lst->next;
	}
	ray_cleanup_obj(ray, ray->obj);
	return (0);
}
