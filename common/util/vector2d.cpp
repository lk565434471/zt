#include "util/vector2d.h"

namespace util {

Vector2D::Vector2D(int32 x, int32 y)
	: x_(x), y_(y)
{
}

Vector2D::~Vector2D()
{
}

void Vector2D::setX(int32 x)
{
	this->x_ = x;
}

int32 Vector2D::getX() const
{
	return this->x_;
}

void Vector2D::setY(int32 y)
{
	this->y_ = y;
}

int32 Vector2D::getY() const
{
	return this->y_;
}

void Vector2D::setPosition(int32 x, int32 y)
{
	this->setX(x);
	this->setY(y);
}

void Vector2D::getPosition(int32 &x, int32 &y)
{
	x = this->getX();
	y = this->getY();
}

int32 Vector2D::getDistance(const Vector2D &direction) const
{
	int32 dx = this->getX() - direction.getX();
	int32 dy = this->getY() - direction.getY();

	return std::abs(std::sqrt((dx * dx) + (dy * dy)));
}

} // namespace util