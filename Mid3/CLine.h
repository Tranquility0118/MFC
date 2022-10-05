#pragma once

// CLine 명령 대상

class CLine : public CObject
{
	DECLARE_SERIAL(CLine)
public:
	CLine();
	CLine(CPoint From, CPoint To, int Size, COLORREF Col) {
		m_From = From; m_To = To;
		m_Size = Size; m_Col = Col;
	}
	void Draw(CDC* pDC) {
		CPen pen(PS_SOLID, m_Size, m_Col);
		pDC->SelectObject(&pen);
		pDC->MoveTo(m_From); pDC->LineTo(m_To);
	}
	virtual ~CLine();
	CPoint m_From, m_To;
	COLORREF m_Col;
	int m_Size;
	virtual void Serialize(CArchive& ar);
};


