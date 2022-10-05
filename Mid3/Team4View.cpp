
// Team4View.cpp: CTeam4View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Team4.h"
#endif

#include "Team4Doc.h"
#include "Team4View.h"
#include"CLine.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTeam4View

IMPLEMENT_DYNCREATE(CTeam4View, CFormView)

BEGIN_MESSAGE_MAP(CTeam4View, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_COMMAND(ID_MENU_COL, &CTeam4View::OnMenuCol)
	ON_COMMAND(ID_SIZE_1, &CTeam4View::OnSize1)
	ON_COMMAND(ID_SIZE_16, &CTeam4View::OnSize16)
	ON_COMMAND(ID_SIZE_8, &CTeam4View::OnSize8)
END_MESSAGE_MAP()

// CTeam4View 생성/소멸

CTeam4View::CTeam4View() noexcept
	: CFormView(IDD_TEAM4_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CTeam4View::~CTeam4View()
{
}

void CTeam4View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CTeam4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CTeam4View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	size = 16;
	
}


// CTeam4View 인쇄

BOOL CTeam4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CTeam4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CTeam4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CTeam4View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CTeam4View 진단

#ifdef _DEBUG
void CTeam4View::AssertValid() const
{
	CFormView::AssertValid();
}

void CTeam4View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTeam4Doc* CTeam4View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTeam4Doc)));
	return (CTeam4Doc*)m_pDocument;
}
#endif //_DEBUG


// CTeam4View 메시지 처리기


void CTeam4View::OnMouseMove(UINT nFlags, CPoint point)
{
	if (nFlags & MK_LBUTTON) {
		CLine* p = new CLine(opnt, point, size, col);
		GetDocument()->m_oa.Add(p);
		Invalidate(false);
	}
	opnt = point;

	CFormView::OnMouseMove(nFlags, point);
}


void CTeam4View::OnPaint()
{
	CPaintDC dc(this); 
	int n = GetDocument()->m_oa.GetSize();
	for (int i = 0; i < n; i++) {
		CLine* p = (CLine*)GetDocument()->m_oa[i];
		p->Draw(&dc);
	}
}


void CTeam4View::OnMenuCol()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		col = dlg.GetColor();
	}
	dlg.DoModal();
}


void CTeam4View::OnSize1()
{
	size = 1;
}


void CTeam4View::OnSize16()
{
	size = 16;
}


void CTeam4View::OnSize8()
{
	size = 8;
}
