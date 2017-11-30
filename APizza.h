//
// EPITECH PROJECT, 2017
// 
// File description:
//
//

#ifndef PLAZZAV1_APIZZA_H
#define PLAZZAV1_APIZZA_H

#include <string>

typedef enum {
	MARGARITA,
	REGINA,
	AMERICAN,
	FANTASIA

} pizzaType;

class APizza {
public:
	float getCookingTime() const;

	pizzaType getType() const;

	const std::string &getSize() const;

protected:
	pizzaType type;
	std::string size;
	float cookingTime;
};


#endif //PLAZZAV1_APIZZA_H
