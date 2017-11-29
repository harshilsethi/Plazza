/*
** EPITECH PROJECT, 2017
** tests_Cooker
** File description:
** Cooker
*/

#include <criterion/criterion.h>
#include "Cooker.h"

Cooker cooker = new Cooker();

Test(getKitchen, return_value_is_good)
{
        int	exceptedValue = 2;
        cr_assert_eq(cooker.getKitchen(), exceptedValue);
}

Test(getKitchen, return_value_is_bad)
{
        cr_assert_neq(cooker.getKitchen(), 0);
        cr_assert_neq(cooker.getKitchen(), 1);
        cr_assert_neq(cooker.getKitchen(), 5);
}