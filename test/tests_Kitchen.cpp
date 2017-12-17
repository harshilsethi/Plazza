/*
** EPITECH PROJECT, 2017
** tests_Kitchen
** File description:
** Kitchen
*/

#include <gtest/gtest.h>
#include "../Kitchen.h"

Kitchen kitchen(5, 3);

TEST(KitchenTest, getMaxCookers_good)
{
	int exceptedValue = 3;

	EXPECT_EQ(kitchen.getNbMaxCookers(), exceptedValue);
}

TEST(KitchenTest, getMaxCookers_bad)
{
        EXPECT_NE(kitchen.getNbMaxCookers(), 0);
        EXPECT_NE(kitchen.getNbMaxCookers(), 1);
        EXPECT_NE(kitchen.getNbMaxCookers(), 5);
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