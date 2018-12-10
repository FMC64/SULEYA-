/*
** EPITECH PROJECT, 2018
** __pretty_much_accurate__runner
** File description:
** render stuff
*/

#include "headers.h"

sfRenderStates get_default_render_states(void)
{
    sfRenderStates res;

    res.blendMode.colorSrcFactor = sfBlendFactorSrcAlpha;
    res.blendMode.colorDstFactor = sfBlendFactorOneMinusSrcAlpha;
    res.blendMode.colorEquation = sfBlendEquationAdd;
    res.blendMode.alphaSrcFactor = sfBlendFactorOne;
    res.blendMode.alphaDstFactor = sfBlendFactorZero;
    res.blendMode.alphaEquation = sfBlendEquationAdd;
    for (int i = 0; i < 9; i++)
        res.transform.matrix[i] = 0.0;
    res.transform.matrix[0] = 1.0f;
    res.transform.matrix[4] = 1.0f;
    res.transform.matrix[8] = 1.0f;
    res.texture = NULL;
    res.shader = NULL;
    return (res);
}
