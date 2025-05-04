#include "pch.h"
#include "CCore.h"
#include "CObject.h"
CObject g_obj;

CCore::CCore() : m_hWnd(0), m_ptResoulution{}, m_hDC(0)
{
}

CCore::~CCore()
{
	ReleaseDC(m_hWnd, m_hDC);
}


int CCore::Init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResoulution = _ptResolution;
	// 해상도에 맞게 윈도우 크기 조정
	RECT rt = {0, 0, m_ptResoulution.x, m_ptResoulution.y};
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hDC = GetDC(m_hWnd); // DC활용해서 그림을 그려야해

	g_obj.m_ptPos = POINT{ m_ptResoulution.x / 2, m_ptResoulution.y / 2};
	g_obj.m_ptScale = POINT{ 100, 100 };
	return 0;
}

void CCore::Update()
{
	static int callcount = 0;
	++callcount;
	static int iPrevCount = GetTickCount();

	int iCurCount = GetTickCount();
	if (iCurCount - iPrevCount > 1000) // 1초마다 한번씩 실행
	{
		iPrevCount = iCurCount;
		callcount = 0;
	}
	update();
	render();
}

void CCore::update() // 물체의 변경점 체크
{
	// 비동기 키 입출력 함수 - 키가 눌리는 순간에 바로체크
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		g_obj.m_ptPos.x -= 1;
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		g_obj.m_ptPos.x += 1;
	}
}

void CCore::render() // 처리되는속도가빠름
{	// 그리기
	Rectangle(m_hDC, g_obj.m_ptPos.x - g_obj.m_ptScale.x / 2, 
		g_obj.m_ptPos.y - g_obj.m_ptScale.y / 2,
		g_obj.m_ptPos.x + g_obj.m_ptScale.x / 2, 
		g_obj.m_ptPos.y + g_obj.m_ptScale.y / 2);
}
