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