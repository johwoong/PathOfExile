#pragma once
struct Vec2 // 힘 방향을 동시에 나타내는 수학적 기호
{
	float x;
	float y;

public:
	Vec2() : x(0.f), y(0.f) {}
	Vec2(float _x, float _y) : x(_x), y(_y){}

	Vec2(int _x, int _y) : x((float)_x), y((float)_y) {}
};

