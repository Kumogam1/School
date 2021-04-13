// Include class definition
#include "GraphicsObject.h"

using namespace Graphics;

// Constructor
GraphicsObject::GraphicsObject()
:	x( 0 )
,	y( 0 )
{
}

// Destructor
GraphicsObject::~GraphicsObject()
{
}

// Position
int GraphicsObject::getPositionX() const
{
	return x;
}

int GraphicsObject::getPositionY() const
{
	return y;
}

void GraphicsObject::setPositionX( int pValue )
{
	x = pValue;
}

void GraphicsObject::setPositionY( int pValue )
{
	y = pValue;
}
