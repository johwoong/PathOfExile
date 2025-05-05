#pragma once
class  CCore
{
	SINGLE(CCore)
private:
	HWND m_hWnd; // 메인 윈도우 핸들
	POINT m_ptResolution; // 메인 윈도우 해상도
	HDC m_hDC;

	HBITMAP m_hBit;
	HDC     m_memDC;

public:
	int Init(HWND _hWnd, POINT _ptResolution);
	void Update();


public:
	HWND GetMainHwnd() { return m_hWnd; }
	HDC GetMainDC() { return m_hDC; }
	POINT GetResolution() { return m_ptResolution; }
};


