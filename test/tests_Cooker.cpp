/*
** EPITECH PROJECT, 2017
** tests_Cooker
** File description:
** Cooker
*/

#include <gtest/gtest.h>
#include "../Cooker.h"
#include "../Pizza/Margarita.h"

class CookerTest : public ::testing::Test {
protected:
        Cooker cooker;
};

TEST_F(CookerTest, getId_good)
{
        EXPECT_EQ(cooker.getId(), 1);
}

TEST_F(CookerTest, getId_bad)
{
        EXPECT_NE(cooker.getId(), -1);
}

TEST_F(CookerTest, getKitchen_good)
{
        EXPECT_EQ(cooker.getKitchen(), cooker.getKitchen());
}

TEST_F(CookerTest, getKitchen_bad)
{
        Kitchen *kitchen = nullptr;

        EXPECT_NE(cooker.getKitchen(), kitchen);
}