
// Mid2View.cpp: CMid2View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Mid2.h"
#endif

#include "Mid2Doc.h"
#include "Mid2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMid2View

IMPLEMENT_DYNCREATE(CMid2View, CView)

BEGIN_MESSAGE_MAP(CMid2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SIZE_1, &CMid2View::OnSize1)
	ON_COMMAND(ID_SEL_COL, &CMid2View::OnSelCol)
	ON_COMMAND(ID_SIZE_8, &CMid2View::OnSize8)
	ON_COMMAND(ID_SIZE_16, &CMid2View::OnSize16)
END_MESSAGE_MAP()

// CMid2View 생성/소멸

CMid2View::CMid2View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMid2View::~CMid2View()
{
}

BOOL CMid2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMid2View 그리기
#include "CLine.h"
void CMid2View::OnDraw(CDC* pDC)
{
	CMid2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	INT_PTR n = pDoc->m_oa.GetCount();
	for (int i = 0; i < n; i++) {
		CLine* p = (CLine*)pDoc->m_oa[i];
		p->Draw(pDC);
	}// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMid2View 인쇄

BOOL CMid2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMid2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMid2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMid2View 진단

#ifdef _DEBUG
void CMid2View::AssertValid() const
{
	CView::AssertValid();
}

void CMid2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMid2Doc* CMid2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMid2Doc)));
	return (CMid2Doc*)m_pDocument;
}
#endif //_DEBUG


// CMid2View 메시지 처리기
COLORREF col;
int size;
CPoint opnt;
void CMid2View::OnMouseMove(UINT nFlags, CPoint point)
{
	if (nFlags & MK_LBUTTON) {
		CLine* p = new CLine(opnt, point,size,col);
		GetDocument()->m_oa.Add(p);
		Invalidate(false);
	}
	opnt = point;
	CView::OnMouseMove(nFlags, point);
}


void CMid2View::OnSize1()
{
	size = 1;
}


void CMid2View::OnSelCol()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		col = dlg.GetColor();
	}
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CMid2View::OnSize8()
{
	size = 8;
}


void CMid2View::OnSize16()
{
	size = 16;
}
