#pragma once

// CLine 명령 대상

class CLine : public CObject
{
	
	CPoint m_From, m_To;
	int m_Size;
	COLORREF m_Col;
public:
	CLine();
	CLine(CPoint From, CPoint To,int Size, COLORREF Col) {
		m_From = From;
		m_To = To;
		m_Col = Col;
		m_Size = Size;
	}
	void Draw(CDC* pDC) {
		CPen pen(PS_SOLID, m_Size, m_Col);
		pDC->SelectObject(&pen);
		pDC->MoveTo(m_From);
		pDC->LineTo(m_To);
	}
	virtual ~CLine();
};


