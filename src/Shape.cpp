#include "Shape.h"

Shape::Shape() :
    type_(I),
    x_(10 / 2 - 4 / 2),
    y_(0),
    rotation_(0)
{
}

Shape::Shape(Type type) :
	type_(type),
	x_(10 / 2 - 4 / 2),
	y_(0),
    rotation_(0)
{

}

void Shape::draw(SDL_Renderer* renderer)
{
	switch (type_)
	{
	case I:
		SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0xff);
		break;
	case J:
        SDL_SetRenderDrawColor(renderer, 0x00, 0xcc, 0x00, 0xff);
		break;
	case L:
		SDL_SetRenderDrawColor(renderer, 0xcc, 0xcc, 0x00, 0xff);
		break;
	case O:
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x7F, 0xff);
		break;
	case S:
		SDL_SetRenderDrawColor(renderer, 0xff, 0x7f, 0x00, 0xff);
		break;
	case T:
		SDL_SetRenderDrawColor(renderer, 0x7f, 0x40, 0x00, 0xff);
		break;
	case Z:
		SDL_SetRenderDrawColor(renderer, 0x00, 0x7f, 0x7f, 0xff);
		break;
	}

    

	for (auto x = 0; x < 4; x++)
		for (auto y = 0; y < 4; y++)
		{
			if (isBlock(x,y))
			{
				SDL_Rect rect{ ((x + x_) * 720 / 2 / 10 + 1) +14, ((y + y_) * 720 / 2 / 10 + 1) + 157, 720 / 2 / 10 - 2, 720 / 2 / 10 - 2 };
				SDL_RenderFillRect(renderer, &rect);
			}
		}
}

void Shape::drawNext(SDL_Renderer* renderer)
{
    switch (type_)
    {
    case I:
        SDL_SetRenderDrawColor(renderer, 0xff, 0x00, 0x00, 0xff);
        break;
    case J:
        SDL_SetRenderDrawColor(renderer, 0x00, 0xcc, 0x00, 0xff);
        break;
    case L:
        SDL_SetRenderDrawColor(renderer, 0xcc, 0xcc, 0x00, 0xff);
        break;
    case O:
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x7F, 0xff);
        break;
    case S:
        SDL_SetRenderDrawColor(renderer, 0xff, 0x7f, 0x00, 0xff);
        break;
    case T:
        SDL_SetRenderDrawColor(renderer, 0x7f, 0x40, 0x00, 0xff);
        break;
    case Z:
        SDL_SetRenderDrawColor(renderer, 0x00, 0x7f, 0x7f, 0xff);
        break;
    }



    for (auto x = 0; x < 4; x++)
        for (auto y = 0; y < 4; y++)
        {
            if (isBlock(x, y))
            {
                SDL_Rect rect{ ((x + x_) * 720 / 2 / 10 + 1) + 320, ((y + y_) * 720 / 2 / 10 + 1) + 205, 720 / 2 / 10 - 2, 720 / 2 / 10 - 2 };
                SDL_RenderFillRect(renderer, &rect);
            }
        }
}

void Shape::move(int dx, int dy)
{
	x_ += dx;
	y_ += dy;
}

void Shape::rotate()
{
	rotation_++;
	rotation_ %= 4;
}

bool Shape::isBlock(int x, int y) const 
{
    static const char* Shapes[][4] = {
       {
         " *  "
         " *  "
         " *  "
         " *  ",
         "    "
         "****"
         "    "
         "    ",
         " *  "
         " *  "
         " *  "
         " *  ",
         "    "
         "****"
         "    "
         "    ",
       },
       {
         "  * "
         "  * "
         " ** "
         "    ",
         "    "
         "*   "
         "*** "
         "    ",
         " ** "
         " *  "
         " *  "
         "    ",
         "    "
         "    "
         "*** "
         "  * ",
       },
       {
         " *  "
         " *  "
         " ** "
         "    ",
         "    "
         "*** "
         "*   "
         "    ",
         " ** "
         "  * "
         "  * "
         "    ",
         "  * "
         "*** "
         "    "
         "    ",
       },
       {
         "    "
         " ** "
         " ** "
         "    ",
         "    "
         " ** "
         " ** "
         "    ",
         "    "
         " ** "
         " ** "
         "    ",
         "    "
         " ** "
         " ** "
         "    ",
       },
       {
         "  * "
         " ** "
         " *  "
         "    ",
         "    "
         "**  "
         " ** "
         "    ",
         "  * "
         " ** "
         " *  "
         "    ",
         "    "
         "**  "
         " ** "
         "    ",
       },
       {
         " *  "
         " ** "
         " *  "
         "    ",
         "    "
         "*** "
         " *  "
         "    ",
         " *  "
         "**  "
         " *  "
         "    ",
         " *  "
         "*** "
         "    "
         "    ",
       },
       {
         " *  "
         " ** "
         "  * "
         "    ",
         "    "
         " ** "
         "**  "
         "    ",
         " *  "
         " ** "
         "  * "
         "    ",
         "    "
         " ** "
         "**  "
         "    ",
       },
    };
    return Shapes[type_][rotation_][x + y * 4] == '*';
}

int Shape::getType() const
{
    return type_;
}

int Shape::x() const
{
    return x_;
}

int Shape::y() const
{
    return y_;
}