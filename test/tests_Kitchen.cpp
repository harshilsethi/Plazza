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

TEST(giveOrder, return_value_is_good)
{
        std::queue<std::string> orders;
        std::string margarita = "margarita";

        orders.push(margarita);
        EXPECT_EQ(orders.front(), margarita);
}

TEST(giveOrder, return_value_is_bad)
{
        std::queue<std::string> orders;
        std::string margarita = "margarita";
        std::string regina = "regina";

        orders.push(margarita);
        orders.push(regina);
        EXPECT_NE(orders.front(), regina);
}

/*
Test(getStatus, return_value_is_good)
{
        if(kitchen)
	        cr_assert_eq(kitchen.getStatus(), true);
        else
                cr_assert_eq(kitchen.getStatus(), false);
}
*/