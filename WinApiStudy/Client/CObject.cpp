#include "pch.h"
#include "CObject.h"
#include "CColider.h"

CObject::CObject() : m_vPos{}, m_vScale{}
{
}

CObject::~CObject()
{
	if (nullptr != m_pColider)
		delete m_pColider;
}

void CObject::CreateColider()
{
	m_pColider = new CColider;
	m_pColider->m_pOwner = this;
}


void CObject::finalupdate()
{
	if (m_pColider)
		m_pColider->finalupdate();
}

void CObject::render(HDC _dc)
{
	Rectangle(_dc, (int)(m_vPos.x - m_vScale.x / 2.f), (int)(m_vPos.y - m_vScale.y / 2.f),
		(int)(m_vPos.x + m_vScale.x / 2.f), (int)(m_vPos.y + m_vScale.y / 2.f));

	component_render(_dc);
}

void CObject::component_render(HDC _dc)
{
	if (nullptr != m_pColider)
	{
		m_pColider->render(_dc);
	}
}