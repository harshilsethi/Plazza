/*
** EPITECH PROJECT, 2017
** Piscine CPP
** File description:
** APizza.cpp
*/

#include "APizza.h"

APizza::APizza(const std::string &size) : size(size) {
}

std::string APizza::getSize() {
	return this->size;
}