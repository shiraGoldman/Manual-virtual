#include <iostream>
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"

using namespace std;

/**
calls the appropriate function of a shape, via vtable (order of functions is known)
@param the pointer to the shape
*/
void invokeArea(Shape* p)
{
	typedef void(*print)(void*);

	unsigned int vtblAddress = *(unsigned int*)p; // because first 4 bytes of the class is the vtable pointer

	print printShape = (print)(*(unsigned int*)(vtblAddress));

	printShape(p);
}

int main()
{
	Shape* shape = NULL;
	shape = new Shape();
	invokeArea(shape);
	delete shape;
	shape = new Rectangle();
	invokeArea(shape);
	delete shape;
	shape = new Triangle();
	invokeArea(shape);
	return 0;
}