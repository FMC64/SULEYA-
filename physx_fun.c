/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** physics stuff
*/

#include "headers.h"

static void phys_fun_ptofun_inter_found(p_in_geom_t in, seg2 fun_line,
vec2 norm, vec2 *vec)
{
    vec2 to_add;
    float t;

    if (vec2_dot(*vec, norm) >= 0.0f)
        return;
    norm = vec2_add(in.p, norm);
    inter2d((seg2){{in.p, norm}}, fun_line, NULL, &t);
    to_add = vec2_sub(seg2_interp(fun_line, t), in.p);
    vec->x += to_add.x * in.bounce;
    vec->y += to_add.y * in.bounce;
}

static void phys_fun_ptofun(mesh_t *obs, vec2 to_ext, vec2 *vec, float bounce)
{
    seg2 seg = {{to_ext, {to_ext.x + vec->x, to_ext.y + vec->y}}};
    seg2 seg_obs;
    float ta;
    float tb;

    for (size_t i = 0; i < obs->count; i++) {
        seg_obs = (seg2){{obs->vertex[i], obs->vertex[i + 1]}};
        inter2d(seg, seg_obs, &ta, &tb);
        if (((ta >= 0.0f) && (ta <= 1.0f)) && ((tb >= 0.0f) && (tb <= 1.0f))) {
            phys_fun_ptofun_inter_found((p_in_geom_t){seg.p[1], bounce},
            seg_obs, obs->norm[i], vec);
            seg = (seg2){{to_ext, {to_ext.x + vec->x, to_ext.y + vec->y}}};
        }
    }
}

static mesh_t get_fun_mesh(obj_fun_t *fun)
{
    mesh_t res;

    for (size_t i = 0; i < fun->mesh.count; i++) {
        res.vertex[i] = (vec2){fun->pos.x + fun->mesh.vertex[i].x,
        fun->pos.y + fun->mesh.vertex[i].y};
        res.norm[i] = fun->mesh.norm[i];
    }
    res.count = fun->mesh.count;
    res.vertex[res.count] = res.vertex[0];
    return (res);
}

void phys_fun(obj_fun_t *fun, obj_fun_t *obs, vec2 *vec)
{
    mesh_t fun_points;
    mesh_t obs_points;

    if (!obs->is_collider)
        return;
    fun_points = get_fun_mesh(fun);
    obs_points = get_fun_mesh(obs);
    for (size_t i = 0; i < fun_points.count; i++)
        phys_fun_ptofun(&obs_points, fun_points.vertex[i], vec, fun->bounce);
    for (size_t i = 0; i < obs_points.count; i++)
        phys_fun_funtop(&fun_points, obs_points.vertex[i], vec);
}
