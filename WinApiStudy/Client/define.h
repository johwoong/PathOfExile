#pragma once
#define SINGLE(Type) public: static Type* GetInst() \
{\
static Type type; return &type;\
}