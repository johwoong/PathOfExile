#pragma once

class CColider;
class CObject
{
private:
	Vec2 m_vPos;
	Vec2 m_vScale;

	CColider* m_pColider;

public:
	CObject();
	virtual ~CObject();

public:
	void SetPos(Vec2  _vPos) { m_vPos = _vPos; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	Vec2 GetPos() { return m_vPos; }
	Vec2 GetScale() { return m_vScale; }

	CColider* GetColider() { return m_pColider; }

	void CreateColider();
	void component_render(HDC _dc);

public:
	virtual void update() = 0;
	virtual void finalupdate() final;
	virtual void render(HDC _dc);
};
