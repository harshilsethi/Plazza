/*
** EPITECH PROJECT, 2017
** tests_Kitchen
** File description:
** Kitchen
*/

#include <criterion/criterion.h>
#include "Kitchen.h"

Kitchen kitchen = new Kitchen(3);

Test(getNbCookers, return_value_is_good)
{
	int	exceptedValue = 3
	cr_assert_eq(kitchen.getNbCookers(), exceptedValue);
}

Test(getNbCookers, return_value_is_bad)
{
	cr_assert_neq(kitchen.getNbCookers(), 0);
	cr_assert_neq(kitchen.getNbCookers(), 1);
	cr_assert_neq(kitchen.getNbCookers(), 5);
}
