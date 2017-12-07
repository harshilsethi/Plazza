/*
** EPITECH PROJECT, 2017
** Plazza Project
** File description:
** American.h
*/

#ifndef AMERICAN_H__
#define AMERICAN_H__

#include "APizza.h"

class American : public APizza
{
public:
	explicit American(const std::string &size);

	float getCookTime() override;
};

#endif /* ! AMERICAN_H__ */