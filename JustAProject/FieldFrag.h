#pragma once
#pragma once
#include "lib.h"
#include "Sprite.h"
#include "ShaderProgram.h"
#include "Rectangle.h"
#include "Plants.h"


class FieldFrag
{
public:
	FieldFrag();
	~FieldFrag();
	bool isPlanted();
	bool isRipen();
	void setStatus(PlantStatus _stt);
	PlantStatus getStatus();
	int plantID;
	Sprite* image;
	std::clock_t start;
	float life;
private:
	PlantStatus stt;
};