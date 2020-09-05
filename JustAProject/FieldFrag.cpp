#include "FieldFrag.h"

FieldFrag::FieldFrag()
{
}

FieldFrag::~FieldFrag()
{
	delete image;
}

bool FieldFrag::isPlanted()
{
	if(stt != BLANK)
		return true;
	else return false;
}

bool FieldFrag::isRipen()
{
	if (stt != RIPEN)
		return true;
	else return false;
}


void FieldFrag::setStatus(PlantStatus _stt)
{
	stt = _stt;
}

PlantStatus FieldFrag::getStatus()
{
	return stt;
}
