#pragma once
struct Vec2 // 힘 방향을 동시에 나타내는 수학적 기호
{
	float x;
	float y;

public:
	float Length()
	{
		return sqrt(x * x + y * y);
	}
	Vec2& operator =(POINT _pt)
	{
		x = (float)_pt.x;
		y = (float)_pt.y;
	}

	Vec2 operator+(Vec2 _vOther)
	{
		return Vec2(x + _vOther.x, y + _vOther.y);
	}

	Vec2 operator-(Vec2 _vOther)
	{
		return Vec2(x - _vOther.x, y - _vOther.y);
	}

	Vec2 operator*(Vec2 _vOther)
	{
		return Vec2(x * _vOther.x, y * _vOther.y);
	}

	Vec2 operator/(Vec2 _vOther)
	{
		assert(!(0.f == _vOther.x || 0.f == _vOther.y));
		return Vec2(x / _vOther.x, y / _vOther.y);
	}


	Vec2& Normalize()
	{
		float fLen = Length();

		assert(fLen != 0.f);
		x /= fLen;
		y /= fLen;
		return *this;
	}

public:
	Vec2() : x(0.f), y(0.f) {}
	Vec2(float _x, float _y) : x(_x), y(_y) {}

	Vec2(int _x, int _y) : x((float)_x), y((float)_y) {}

	Vec2(const POINT& _pt) : x((float)_pt.x), y((float)_pt.y) {}
};
