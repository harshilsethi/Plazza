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
        int     exceptedValue = cooker.getKitchen();

        EXPECT_EQ(cooker.getKitchen(), exceptedValue);
}

TEST_F(CookerTest, getKitchen_bad)
{
        EXPECT_NE(cooker.getKitchen(), 0);
        EXPECT_NE(cooker.getKitchen(), 1);
        EXPECT_NE(cooker.getKitchen(), 5);
}

/*
TEST(getPizza, return_value_is_good)
{
        Cooker  cooker;
        Margarita       margarita("L");

        EXPECT_EQ(cooker.getPizza(), margarita);
}
*/
