#pragma once
#define SINGLE(Type) public:\
			static Type* GetInst() \
			{\
					static Type type; return &type;\
}\
private:\
	Type();\
	~Type();



#define fDT CTimeMgr::GetInst()->GetfDT();
#define DT CTimeMgr::GetInst()->GetDT();


enum class GROUP_TYPE
{
	DEFAULT, // 0
	PLAYER, // 1
	MISSILE, // 2
	MONSTER, // 3
	END = 32,
};

enum class SCENE_TYPE
{
	TOOL,
	START,
	STAGE_01,
	STAGE_02,
	END,
};