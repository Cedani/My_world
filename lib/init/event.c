/*
** EPITECH PROJECT, 2020
** MUL_my_world_2019
** File description:
** event
*/

#include "../../include/my_world.h"

void analyse_keyboard_event(t_res *res, t_elem *e)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        e->trans.x -= 1;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        e->trans.x += 1;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        e->trans.y -= 1;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        e->trans.y += 1;
    if (sfKeyboard_isKeyPressed(sfKeyI))
        e->ang.z += 0.05;
    if (sfKeyboard_isKeyPressed(sfKeyO) && e->ang.z > 2)
        e->ang.z -= 0.05;
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        e->inc -= 0.01;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        e->inc += 0.01;
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        e->ang.y -= 0.01;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        e->ang.y += 0.01;
}

void analyse_mouse_event(t_res *res, t_elem *e, t_button_list *l)
{
    if (res->event.type == sfEvtMouseMoved
        && is_inmap(e, res->event.mouseMove) == 1) {
            reset_all(e);
            check_button(l, e, res->event.mouseMove);
        }
    if (res->event.type == sfEvtMouseMoved
        && is_inmap(e, res->event.mouseMove) == 0) {
            reset_all(e);
            update_quad_state(e, res->event.mouseMove);
        }
    if (res->event.type == sfEvtMouseButtonPressed
        && is_inmap_button(e, res->event.mouseButton) == 1) {
        if (res->event.key.code == sfMouseLeft) {
            check_click(l, e, res->event.mouseButton);
        }
    }
}

void analyse_event(t_res *res, t_elem *e, t_button_list *l)
{
    change_flat(e, l);
    analyse_keyboard_event(res, e);
    if (res->event.type == sfEvtMouseButtonPressed
        && is_inmap_button(e, res->event.mouseButton) == 0) {
        if (res->event.key.code == sfMouseLeft)
            update_quad(e, res->event.mouseButton);
        if (res->event.key.code == sfMouseRight)
            update_click(e, res->event.mouseButton);
    }
    if (sfKeyboard_isKeyPressed(sfKeyR))
        save(4, e);
    if (sfKeyboard_isKeyPressed(sfKeyL))
        load(4, e);
    analyse_mouse_event(res, e, l);
    check_size(e, l);
}