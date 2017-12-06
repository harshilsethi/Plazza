/*
** EPITECH PROJECT, 2017
** tests_Cooker
** File description:
** Cooker
*/

#include <criterion/criterion.h>
#include "../Cooker.h"
#include "../Pizza/Margarita.h"
#include "../Pizza/Regina.h"
#include "../Pizza/American.h"
#include "../Pizza/Fantasia.h"

Cooker cooker = new Cooker();

Test(getKitchen, return_value_is_good)
{
        int     exceptedValue = 2;

        cr_assert_eq(cooker.getKitchen(), exceptedValue);
}

Test(getKitchen, return_value_is_bad)
{
        cr_assert_eq(cooker.getKitchen(), 0);
        cr_assert_eq(cooker.getKitchen(), 1);
        cr_assert_eq(cooker.getKitchen(), 5);
}

Test(getPizza, return_value_is_good)
{
        Margarita       margarita = new Margarita();
        Regina          regina = new Regina();
        American        american = new American();
        Fantasia        fantasia = new Fantasia();

        cr_assert_eq(cooker.getPizza(), margarita);
        cr_assert_eq(cooker.getPizza(), regina);
        cr_assert_eq(cooker.getPizza(), american);
        cr_assert_eq(cooker.getPizza(), fantasia);
}
