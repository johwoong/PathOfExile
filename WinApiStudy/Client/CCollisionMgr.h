#pragma once

class CColider;
class CCollisionMgr
{
	SINGLE(CCollisionMgr);

private:
	// 충돌체 간의 이전 프레임 충돌 정보
	
	UINT m_arrCheck[(UINT)GROUP_TYPE::END]; // 그룹간의 충돌 체크 매트릭스
public:
	void update();
	void CheckGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
	void Reset()
	{
		memset(m_arrCheck, 0, sizeof(UINT) * (UINT)GROUP_TYPE::END);
	}

private:
	void CollisionUpdateGroup(GROUP_TYPE _eLeft, GROUP_TYPE _eRight);
	bool IsCollision(CColider* _pLeftCol, CColider* _pRightCol);
};

