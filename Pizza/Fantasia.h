/*
** EPITECH PROJECT, 2017
** Piscine CPP
** File description:
** Fantasia.h
*/

#ifndef FANTASIA_H__
#define FANTASIA_H__

#include "APizza.h"

class Fantasia : public APizza
{
public:
	explicit Fantasia(const std::string &size);

	float getCookTime() override;
};

#endif /* ! FANTASIA_H__ */
