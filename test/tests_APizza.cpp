/*
** EPITECH PROJECT, 2017
** tests_APizza
** File description:
** APizza
*/

#include <gtest/gtest.h>
#include "../Pizza/Margarita.h"
#include "../Pizza/Regina.h"
#include "../Pizza/American.h"
#include "../Pizza/Fantasia.h"

Margarita margarita("XL");
Regina regina("L");
American american("M");
Fantasia fantasia("L");

TEST(getSize, return_value_is_good)
{
        EXPECT_EQ(margarita.getSize(), "XL");
        EXPECT_EQ(regina.getSize(), "L");
        EXPECT_EQ(american.getSize(), "M");
        EXPECT_EQ(fantasia.getSize(), "L");
}

TEST(getSize, return_value_is_bad)
{
        EXPECT_NE(margarita.getSize(), "M");
        EXPECT_NE(regina.getSize(), "XL");
        EXPECT_NE(american.getSize(), "L");
        EXPECT_NE(fantasia.getSize(), "M");
}

TEST(getCookTime, return_value_is_good)
{
        EXPECT_EQ(margarita.getCookTime(), 1.5);
        EXPECT_EQ(regina.getCookTime(), 1);
        EXPECT_EQ(american.getCookTime(), 2);
        EXPECT_EQ(fantasia.getCookTime(), 4);
}

TEST(getCookTime, return_value_is_bad)
{
        EXPECT_NE(margarita.getCookTime(), 1);
        EXPECT_NE(regina.getCookTime(), 4);
        EXPECT_NE(american.getCookTime(), 1.5);
        EXPECT_NE(fantasia.getCookTime(), 2);
}

