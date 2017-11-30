/*
** EPITECH PROJECT, 2017
** Piscine CPP
** File description:
** Regina.h
*/

#ifndef REGINA_H__
#define REGINA_H__

#include "APizza.h"

class Regina : public APizza
{
public:
	explicit Regina(const std::string &size);

	float getCookTime() override;
};

#endif /* ! REGINA_H__ */