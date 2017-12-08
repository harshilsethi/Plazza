/*
** EPITECH PROJECT, 2017
** Plazza Project
** File description:
** Margarita.h
*/

#ifndef MARGARITA_H__
#define MARGARITA_H__

#include "APizza.h"

class Margarita : public APizza
{
public:
	explicit Margarita(const std::string &size);

	float getCookTime() override;
};

#endif /* ! MARGARITA_H__ */