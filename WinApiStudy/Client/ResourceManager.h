#pragma once
class CTexture;
class ResourceManager
{
	SINGLE(ResourceManager);
private:
	map<wstring, CTexture*> m_mapTex;
public:
	CTexture* LoadTexture(const wstring& _strKey, const wstring& _strRelativePath);
	CTexture* FindTexture(const wstring& _strKey);


};

