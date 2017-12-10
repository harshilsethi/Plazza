/*
** EPITECH PROJECT, 2017
** tests_Cooker
** File description:
** Cooker
*/

#include <gtest/gtest.h>
#include "../Cooker.h"
#include "../Pizza/Margarita.h"
#include "../Pizza/Regina.h"
#include "../Pizza/American.h"
#include "../Pizza/Fantasia.h"

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
