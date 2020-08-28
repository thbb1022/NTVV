#include "Plants.h"

Plants::Plants(int _ID, int _lifeTime, int _quanity, int _price,
	const char* _icon, const char* _grow, const char* _middle, const char* _ripen)
{
	ID = _ID;
	lifeTime = _lifeTime;
	quanity = _quanity;
	price = _price;
	icon = _icon;
	grow = _grow;
	middle = _middle;
	ripen = _ripen;
}

Plants::~Plants()
{
	delete icon;
	delete grow;
	delete middle;
	delete ripen;
}

int Plants::getId()
{
	return ID;
}

int Plants::getLifeTime()
{
	return lifeTime;
}

int Plants::getPrice()
{
	return price;
}

int Plants::getQuanity()
{
	return quanity;
}

const char* Plants::getImage(PlantStatus stt)
{
	if (stt == GROW)
		return grow;
	if (stt == MIDDLE)
		return middle;
	if (stt == RIPEN)
		return ripen;
}
