// CLine.cpp: 구현 파일
//

#include "pch.h"
#include "Team4.h"
#include "CLine.h"

IMPLEMENT_SERIAL(CLine, CObject, 1);
// CLine

CLine::CLine()
{
}

CLine::~CLine()
{
}


// CLine 멤버 함수


void CLine::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_From << m_To << m_Size << m_Col;
	}
	else
	{	
		ar >> m_From >> m_To >> m_Size >> m_Col;
	}
}
