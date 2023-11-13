#pragma once
/// +------------------
///  코딩 테스트 준비 
/// ------------------+
class CodingTestMgr
{
private:



public:

public:
	static CodingTestMgr* inst;
	static CodingTestMgr* GetInst()
	{
		if (!inst) { inst = new CodingTestMgr{}; return inst; }
		else return inst;
	}
	bool Destroy() { if (inst) delete inst; inst = nullptr; }
};

