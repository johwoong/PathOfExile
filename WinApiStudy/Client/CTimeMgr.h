#pragma once
class CTimeMgr // 시간 동기화
{
	SINGLE(CTimeMgr);
private:
	LARGE_INTEGER m_llPrevCount;
	LARGE_INTEGER m_llFrequency;
	LARGE_INTEGER m_llCurCount;
	// FPS
	// 1 프레임당 시간 Delta Time
	double m_dDT; // 프레임 사이의 시간값
	double m_dAcc; // 1초 체크를 위한 누적 시간
	UINT  m_iCallCount;  // 함수 호출 횟수 체크
	UINT m_iFPS; // 초당 호출 횟수

public:
	void init();
	void update();
	void render();
public:
	double GetDT() { return m_dDT; }
	float GetfDT() { return (float)m_dDT; }
};
