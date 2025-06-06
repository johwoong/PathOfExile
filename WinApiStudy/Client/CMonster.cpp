#include "pch.h"
#include "CMonster.h"
#include "CTimeMgr.h"
#include "CColider.h"

CMonster::CMonster() : m_fSpeed(100.f),
m_vCenterPos(Vec2(0.f, 0.f)),
m_fMaxDistance(50.f), m_iDir(1)
{
	CreateColider();

	GetColider()->SetScale(Vec2(40.f, 40.f));
}

CMonster::~CMonster()
{
}

void CMonster::update()
{
	Vec2 vCurPos = GetPos();
	// 진행 방향으로 시간당 m_fSpeed만큼 이동
	vCurPos.x += m_fSpeed * m_iDir * fDT;

	float fDist = abs(m_vCenterPos.x - vCurPos.x) - m_fMaxDistance;
	// 배회 거리 기준량을 넘어섰는지 확인
	if (0 < fDist)
	{
		// 방향 변경
		m_iDir *= -1;
		vCurPos.x += fDist * m_iDir;
	}

	SetPos(vCurPos);
}