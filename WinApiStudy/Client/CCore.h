#pragma once
class  CCore
{

	SINGLE(CCore);
private:
	HWND m_hWnd; // 메인 윈도우 핸들
	POINT m_ptResoulution; // 메인 윈도우 해상도
	HDC m_hDC;

public:
	int Init(HWND _hWnd, POINT _ptResolution);
	void Update();

private:
	void update();
	void render();

private:
	CCore();
	~CCore();
};


