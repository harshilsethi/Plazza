/*
** EPITECH PROJECT, 2017
** Plazza Project
** File description:
** Fantasia.cpp
*/

#include "Fantasia.h"

Fantasia::Fantasia(const std::string &size) : APizza(size) {
}

float Fantasia::getCookTime() {
	return 4;
}