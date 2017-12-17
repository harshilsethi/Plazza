/*
** EPITECH PROJECT, 2017
** tests_Kitchen
** File description:
** Kitchen
*/

#include <gtest/gtest.h>
#include "../Kitchen.h"
#include "../Cooker.h"

Kitchen kitchen(5, 3);

TEST(getMaxCookers, return_value_is_good)
{
	int exceptedValue = 3;

	EXPECT_EQ(kitchen.getMaxCookers(), exceptedValue);
}

TEST(getMaxCookers, return_value_is_bad)
{
        EXPECT_NE(kitchen.getMaxCookers(), 0);
        EXPECT_NE(kitchen.getMaxCookers(), 1);
        EXPECT_NE(kitchen.getMaxCookers(), 5);
}

TEST(giveOrder, return_value_is_good)
{
        std::queue<std::string> orders;
        std::string margarita = "margarita";

        orders.push(margarita);
        EXPECT_EQ(orders.front(), margarita);
}
/*
TEST(getCookers, return_value_is_good)
{
        std::list<Cooker> cookers;

        EXPECT_EQ(kitchen.getCookers(), cookers);
}
*/
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