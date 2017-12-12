/*
** EPITECH PROJECT, 2017
** tests_Cooker
** File description:
** Cooker
*/

#include <gtest/gtest.h>
#include "../Cooker.h"
#include "../Pizza/Margarita.h"

TEST(getId, return_value_is_good)
{
        Cooker cooker;

        EXPECT_EQ(cooker.getId(), 1);
}

TEST(getId, return_value_is_bad)
{
        Cooker cooker;

        EXPECT_NE(cooker.getId(), -1);
}

TEST(getKitchen, return_value_is_good)
{
        Cooker cooker;
        int     exceptedValue = cooker.getKitchen();

        EXPECT_EQ(cooker.getKitchen(), exceptedValue);
}

TEST(getKitchen, return_value_is_bad)
{
        Cooker  cooker;

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
