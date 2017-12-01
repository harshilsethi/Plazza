/*
** EPITECH PROJECT, 2017
** tests_APizza
** File description:
** APizza
*/

#include <criterion/criterion.h>
#include "Margarita.h"
#include "Regina.h"
#include "American.h"
#include "Fantasia.h"

Margarita margarita = new Margarita("XL");
Regina regina = new Regina("L");
American american = new American("M");
Fantasia fantasia = new Fantasia("L");

Test(getSize, return_value_is_good)
{
        cr_str_assert_eq(margarita.getSize(), "XL");
        cr_str_assert_eq(regina.getSize(), "L");
        cr_str_assert_eq(american.getSize(), "M");
        cr_str_assert_eq(fantasia.getSize(), "L");
}

Test(getSize, return_value_is_bad)
{
        cr_str_assert_neq(margarita.getSize(), "M");
        cr_str_assert_neq(regina.getSize(), "XL");
        cr_str_assert_neq(american.getSize(), "L");
        cr_str_assert_neq(fantasia.getSize(), "M");
}

Test(getCookTime, return_value_is_good)
{
        cr_assert_eq(margarita.getCookTime(), 1.5);
        cr_assert_eq(regina.getCookTime(), 1);
        cr_assert_eq(american.getCookTime(), 2);
        cr_assert_eq(fantasia.getCookTime(), 4);
}

Test(getCookTime, return_value_is_good)
{
        cr_assert_neq(margarita.getCookTime(), 1);
        cr_assert_neq(regina.getCookTime(), 4);
        cr_assert_neq(american.getCookTime(), 1.5);
        cr_assert_neq(fantasia.getCookTime(), 2);
}

