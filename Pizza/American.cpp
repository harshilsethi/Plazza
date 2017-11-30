/*
** EPITECH PROJECT, 2017
** Piscine CPP
** File description:
** American.cpp
*/

#include "American.h"

American::American(const std::string &size) : APizza(size) {}

float American::getCookTime() {
	return 2;
}