#include "pch.h"
#include "CColider.h"
#include "CObject.h"
#include "CCore.h"
#include "SelectGDI.h"

UINT CColider::g_iNextID = 0;

CColider::CColider() : m_pOwner(nullptr), m_iID(g_iNextID++)
{

}

CColider::~CColider()
{
}

void CColider::finalupdate()
{
	// Object의 위치를 따라가겠다.
	Vec2 vObjectPos = m_pOwner->GetPos();
	m_vFinalPos = vObjectPos + m_vOffsetPos;
}

void CColider::render(HDC _dc)
{
	SelectGDI p(_dc, PEN_TYPE::GREEN);
	SelectGDI b(_dc, BRUSH_TYPE::HOLLOW);

	Rectangle(_dc
		, (int)(m_vFinalPos.x - m_vScale.x / 2.f)
		, (int)(m_vFinalPos.y - m_vScale.y / 2.f)
		, (int)(m_vFinalPos.x + m_vScale.x / 2.f)
		, (int)(m_vFinalPos.y + m_vScale.y / 2.f));
}
