
// Team4View.h: CTeam4View 클래스의 인터페이스
//

#pragma once


class CTeam4View : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CTeam4View() noexcept;
	DECLARE_DYNCREATE(CTeam4View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_TEAM4_FORM };
#endif

// 특성입니다.
public:
	CTeam4Doc* GetDocument() const;
	CPoint opnt;
	int size;
	COLORREF col;
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CTeam4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnMenuCol();
	afx_msg void OnSize1();
	afx_msg void OnSize16();
	afx_msg void OnSize8();
};

#ifndef _DEBUG  // Team4View.cpp의 디버그 버전
inline CTeam4Doc* CTeam4View::GetDocument() const
   { return reinterpret_cast<CTeam4Doc*>(m_pDocument); }
#endif

