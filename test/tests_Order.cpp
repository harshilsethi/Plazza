/*
** EPITECH PROJECT, 2017
** Piscine CPP
** File description:
** tests_Order.cpp
*/

#include <gtest/gtest.h>
#include "../Order.h"

class OrderTest : public ::testing::Test {
protected:
        Order order;
};

TEST_F(OrderTest, getId_good)
{
        EXPECT_EQ(order.getId(), order.getId());
}

TEST_F(OrderTest, getId_bad)
{
        EXPECT_NE(order.getId(), -1);
}

TEST_F(OrderTest, getCommand_good)
{
        std::string pizza = "Margarita XL 2";

        order.setCommand(pizza);
        EXPECT_EQ(order.getCommand(), pizza);
}

TEST_F(OrderTest, getCommand_bad)
{
        std::string pizza = "Margarita";

        order.setCommand(pizza);
        EXPECT_NE(order.getCommand(), "Margarita XL 2");
}