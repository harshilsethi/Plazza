/*
** EPITECH PROJECT, 2017
** tests_Kitchen
** File description:
** Kitchen
*/

#include <gtest/gtest.h>
#include "../Kitchen.h"
#include "../Cooker.h"

Kitchen kitchen(3);

TEST(getNbCookers, return_value_is_good)
{
	int	exceptedValue = 3;

	EXPECT_EQ(kitchen.getNbCookers(), exceptedValue);
}

TEST(getNbCookers, return_value_is_bad)
{
        EXPECT_NE(kitchen.getNbCookers(), 0);
        EXPECT_NE(kitchen.getNbCookers(), 1);
        EXPECT_NE(kitchen.getNbCookers(), 5);
}
/*
Test(getCookers, return_value_is_good)
{
	std::list<Cooker> cookers;
	Cooker chef;

        cookers.push_back(chef);

	cr_assert_eq(kitchen.getCookers(), cookers);
}

Test(getStatus, return_value_is_good)
{
        if(kitchen)
	        cr_assert_eq(kitchen.getStatus(), true);
        else
                cr_assert_eq(kitchen.getStatus(), false);
}
*/