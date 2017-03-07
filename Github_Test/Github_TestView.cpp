
// Github_TestView.cpp : CGithub_TestView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Github_Test.h"
#endif

#include "Github_TestDoc.h"
#include "Github_TestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGithub_TestView

IMPLEMENT_DYNCREATE(CGithub_TestView, CView)

BEGIN_MESSAGE_MAP(CGithub_TestView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGithub_TestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CGithub_TestView ����/����

CGithub_TestView::CGithub_TestView()
{
	// TODO: �ڴ˴���ӹ������

}

CGithub_TestView::~CGithub_TestView()
{
}

BOOL CGithub_TestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CGithub_TestView ����

void CGithub_TestView::OnDraw(CDC* /*pDC*/)
{
	CGithub_TestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CGithub_TestView ��ӡ


void CGithub_TestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGithub_TestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CGithub_TestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CGithub_TestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CGithub_TestView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGithub_TestView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CGithub_TestView ���

#ifdef _DEBUG
void CGithub_TestView::AssertValid() const
{
	CView::AssertValid();
}

void CGithub_TestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGithub_TestDoc* CGithub_TestView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGithub_TestDoc)));
	return (CGithub_TestDoc*)m_pDocument;
}
#endif //_DEBUG


// CGithub_TestView ��Ϣ�������
