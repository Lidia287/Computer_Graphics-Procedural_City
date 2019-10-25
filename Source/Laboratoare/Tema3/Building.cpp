#include "Building.h"


void  Building::setValues(float x, float y, float z, int numberOfSpaces, int numberOfComponents)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->numberOfSpaces = numberOfSpaces;
	this->numberOfComponents = numberOfComponents;

}


void  Building::setValues(float x, float y, float z, int numberOfSpaces, float x2, float y2, float z2, int type)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->numberOfSpaces = numberOfSpaces;
	this->x2 = x2;
	this->y2 = y2;
	this->z2 = z2;
	this->type = type;
}

void Building::setValues(float sx1, float sy1, float sz1)
{
	this->sx1 = sx1;
	this->sy1 = sy1;
	this->sz1 = sz1;

}
void Building::setValues(float sx1, float sy1, float sz1, float sx2, float sy2, float sz2)
{

	this->sx1 = sx1;
	this->sy1 = sy1;
	this->sz1 = sz1;

	this->sx2 = sx2;
	this->sy2 = sy2;
	this->sz2 = sz2;
}
void Building::setValues(float sx1, float sy1, float sz1, float sx2, float sy2, float sz2, float sx3, float sy3, float sz3)
{
	this->sx1 = sx1;
	this->sy1 = sy1;
	this->sz1 = sz1;

	this->sx2 = sx2;
	this->sy2 = sy2;
	this->sz2 = sz2;

	this->sx3 = sx3;
	this->sy3 = sy3;
	this->sz3 = sz3;
}