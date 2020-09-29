#pragma once

#include "common.h"

namespace util {

class Vector2D
{
public:

	Vector2D(int32 x = 0, int32 y = 0);

	~Vector2D();

public:

	void setX(int32 x);
	int32 getX() const;
	void setY(int32 y);
	int32 getY() const;

	void setPosition(int32 x, int32 y);
	void getPosition(int32 &x, int32 &y);

	int32 getDistance(const Vector2D &direction) const;

private:

	int32 x_;
	int32 y_;
};

} // namespace util