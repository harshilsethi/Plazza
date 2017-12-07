/*
** EPITECH PROJECT, 2017
** Plazza Project
** File description:
** APizza.cpp
*/

#include "APizza.h"

APizza::APizza(const std::string &size) : size(size) {
}

std::string APizza::getSize() {
	return this->size;
}

float APizza::getCookTime() {
	return 0;
}