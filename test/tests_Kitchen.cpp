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

TEST(KitchenTest, getMaxCookers_good)
{
	int exceptedValue = 3;

	EXPECT_EQ(kitchen.getMaxCookers(), exceptedValue);
}

TEST(KitchenTest, getMaxCookers_bad)
{
        EXPECT_NE(kitchen.getMaxCookers(), 0);
        EXPECT_NE(kitchen.getMaxCookers(), 1);
        EXPECT_NE(kitchen.getMaxCookers(), 5);
}

TEST(KitchenTest, giveOrder_good)
{
        std::queue<std::string> orders;
        std::string margarita = "margarita";

        orders.push(margarita);
        EXPECT_EQ(orders.front(), margarita);
}

TEST(KitchenTest, giveOrder_bad)
{
        std::queue<std::string> orders;
        std::string margarita = "margarita";
        std::string regina = "regina";

        orders.push(margarita);
        orders.push(regina);
        EXPECT_NE(orders.front(), regina);
}

/*
TEST(getCookers, return_value_is_good)
{
        std::list<Cooker> cookers;

        EXPECT_NE(kitchen.getCookers(), cookers);
}
*/