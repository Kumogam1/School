#ifndef _GRAPHICS_OBJECT_H_
#define _GRAPHICS_OBJECT_H_

#include <vector>
#include <utility>

//std::pair< int, int >a;
//	a.first = 2;
//	a.second = 3;
//	std::pair< int, int >a = std::make_pair(  -2 , 1 );
//	std::pair< int, int >a( 1, 3);

namespace Graphics
{

class GraphicsObject
{

public:

	// Desctructor
	virtual ~GraphicsObject();

	// Position
	int getPositionX() const;
	int getPositionY() const;
	void setPositionX( int pValue );
	void setPositionY( int pValue );

	using TCoordinate = std::pair< int, int >;
	using TShape = std::vector< TCoordinate >;
	using TRotatedShapes = std::vector< TShape >;
	TRotatedShapes tiles_;

protected:

	// Constructor
	GraphicsObject();

private:

    // Position
	int x;
	int y;

};

//////////////////////////////////////////////////////////////////////////////////////////
// shape I
//////////////////////////////////////////////////////////////////////////////////////////
class ShapeI : public GraphicsObject
{
public:
	static ShapeI* create();
	virtual ~ShapeI();
protected:
	ShapeI();
private:
};
ShapeI* ShapeI::create()
{
	return new ShapeI();
}

ShapeI::ShapeI()
	: GraphicsObject()
{
	tiles_.resize(4/*nb rotations*/);
	// shape : I
	tiles_[0] = { std::make_pair(0, 0),
					std::make_pair(1, 0),
					std::make_pair(2, 0),
					std::make_pair(3, 0) };
	tiles_[1] = { std::make_pair(0, 0),
					std::make_pair(0, 1),
					std::make_pair(0, 2),
					std::make_pair(0, 3) };
	tiles_[2] = tiles_[0];
	tiles_[3] = tiles_[1];
}
ShapeI::~ShapeI()
{
}

//////////////////////////////////////////////////////////////////////////////////////////
// shape O
//////////////////////////////////////////////////////////////////////////////////////////
class ShapeO : public GraphicsObject
{
public:
	static ShapeO* create();
	virtual ~ShapeO();
protected:
	ShapeO();
private:
};
ShapeO* ShapeO::create()
{
	return new ShapeO();
}
ShapeO::ShapeO()
	: GraphicsObject()
{
	tiles_.resize(4/*nb rotations*/);
	// shape : O
	tiles_[0] = { std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(1, 1) };
	tiles_[1] = tiles_[0];
	tiles_[2] = tiles_[0];
	tiles_[3] = tiles_[0];
}
ShapeO::~ShapeO()
{
}

//////////////////////////////////////////////////////////////////////////////////////////
// shape T
//////////////////////////////////////////////////////////////////////////////////////////
class ShapeT : public GraphicsObject
{
public:
	static ShapeT* create();
	virtual ~ShapeT();
protected:
	ShapeT();
private:
};
ShapeT* ShapeT::create()
{
	return new ShapeT();
}
ShapeT::ShapeT()
	: GraphicsObject()
{
	tiles_.resize(4/*nb rotations*/);
	// shape : T
	tiles_[0] = { std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(0, 1) };
	tiles_[1] = { std::make_pair(-1, 1), std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2) };
	tiles_[2] = { std::make_pair(0, 0), std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(1, 1) };
	tiles_[3] = { std::make_pair(-1, 0), std::make_pair(-1, 1), std::make_pair(-1, 2), std::make_pair(0, 1) };
}
ShapeT::~ShapeT()
{
}

//////////////////////////////////////////////////////////////////////////////////////////
// shape L
//////////////////////////////////////////////////////////////////////////////////////////
class ShapeL : public GraphicsObject
{
public:
	static ShapeL* create();
	virtual ~ShapeL();
protected:
	ShapeL();
private:
};
ShapeL* ShapeL::create()
{
	return new ShapeL();
}
ShapeL::ShapeL()
	: GraphicsObject()
{
	tiles_.resize(4/*nb rotations*/);
	// shape : L
	tiles_[0] = { std::make_pair(-1, 0), std::make_pair(-1, -1), std::make_pair(0, -1), std::make_pair(1, -1) };
	tiles_[1] = { std::make_pair(-1, -1), std::make_pair(0, -1), std::make_pair(0, 0), std::make_pair(0, 1) };
	tiles_[2] = { std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(1, -1) };
	tiles_[3] = { std::make_pair(0, -1), std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(1, 1) };
}
ShapeL::~ShapeL()
{
}


//////////////////////////////////////////////////////////////////////////////////////////
// shape J
//////////////////////////////////////////////////////////////////////////////////////////
class ShapeJ : public GraphicsObject
{
public:
	static ShapeJ* create();
	virtual ~ShapeJ();
protected:
	ShapeJ();
private:
};
ShapeJ* ShapeJ::create()
{
	return new ShapeJ();
}
ShapeJ::ShapeJ()
	: GraphicsObject()
{
	tiles_.resize(4/*nb rotations*/);
	// shape : J
	tiles_[0] = { std::make_pair(-1,0), std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(1, -1) };
	tiles_[1] = { std::make_pair(-1, -1), std::make_pair(0, -1), std::make_pair(0, 0), std::make_pair(0, 1) };
	tiles_[2] = { std::make_pair(-1, 0), std::make_pair(-1, -1), std::make_pair(0, -1), std::make_pair(1, -1) };
	tiles_[3] = { std::make_pair(0, -1), std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(1, 1) };
}
ShapeJ::~ShapeJ()
{
}
//////////////////////////////////////////////////////////////////////////////////////////
// shape Z
//////////////////////////////////////////////////////////////////////////////////////////
class ShapeZ : public GraphicsObject
{
public:
	static ShapeZ* create();
	virtual ~ShapeZ();
protected:
	ShapeZ();
private:
};
ShapeZ* ShapeZ::create()
{
	return new ShapeZ();
}
ShapeZ::ShapeZ()
	: GraphicsObject()
{
	tiles_.resize(4/*nb rotations*/);
	// shape : I
	tiles_[0] = { std::make_pair(-1, 0), std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(1, 1) };
	tiles_[1] = { std::make_pair(0, 0), std::make_pair(-1, 1), std::make_pair(0, 1), std::make_pair(-1, 2) };
	tiles_[2] = tiles_[0];
	tiles_[3] = tiles_[1];
}
ShapeZ::~ShapeZ()
{
}

//////////////////////////////////////////////////////////////////////////////////////////
// shape S
//////////////////////////////////////////////////////////////////////////////////////////
class ShapeS : public GraphicsObject
{
public:
	static ShapeS* create();
	virtual ~ShapeS();
protected:
	ShapeS();
private:
};
ShapeS* ShapeS::create()
{
	return new ShapeS();
}
ShapeS::ShapeS()
	: GraphicsObject()
{
	tiles_.resize(4/*nb rotations*/);
	// shape : S
	tiles_[0] = { std::make_pair(1, 0), std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(-1, 1) };
	tiles_[1] = { std::make_pair(0, 0), std::make_pair(1, 1), std::make_pair(0, 1), std::make_pair(1, 2) };
	tiles_[2] = tiles_[0];
	tiles_[3] = tiles_[1];
}
ShapeS::~ShapeS()
{
}


}


#endif
