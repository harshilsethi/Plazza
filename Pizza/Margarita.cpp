/*
** EPITECH PROJECT, 2017
** Plazza Project
** File description:
** Margarita.cpp
*/

#include "Margarita.h"

Margarita::Margarita(const std::string &size) : APizza(size) {}

float Margarita::getCookTime() {
	return 1.5;
}