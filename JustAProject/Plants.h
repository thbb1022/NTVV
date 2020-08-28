#pragma once
#pragma once
#include "lib.h"
#include "Sprite.h"
#include "ShaderProgram.h"
#include "Rectangle.h"


enum PlantStatus
{
	BLANK,
	GROW,
	MIDDLE,
	RIPEN
};

class Plants
{
public:
	Plants(int _ID, int _lifeTime, int _quanity, int _price,
		const char* _icon, const char* _grow, const char* _middle, const char* _ripen);
	~Plants();

	int getId();
	int getLifeTime();
	int getPrice();
	int getQuanity();
	const char* Plants::getImage(PlantStatus stt);
private:
	int ID;
	int lifeTime;
	int quanity;
	int price;
	const char* icon;
	const char* grow;
	const char* middle;
	const char* ripen;
};