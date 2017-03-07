
// Github_TestView.cpp : CGithub_TestView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGithub_TestView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CGithub_TestView 构造/析构

CGithub_TestView::CGithub_TestView()
{
	// TODO: 在此处添加构造代码

}

CGithub_TestView::~CGithub_TestView()
{
}

BOOL CGithub_TestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CGithub_TestView 绘制

void CGithub_TestView::OnDraw(CDC* /*pDC*/)
{
	CGithub_TestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CGithub_TestView 打印


void CGithub_TestView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CGithub_TestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CGithub_TestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CGithub_TestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
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


// CGithub_TestView 诊断

#ifdef _DEBUG
void CGithub_TestView::AssertValid() const
{
	CView::AssertValid();
}

void CGithub_TestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGithub_TestDoc* CGithub_TestView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGithub_TestDoc)));
	return (CGithub_TestDoc*)m_pDocument;
}
#endif //_DEBUG


// CGithub_TestView 消息处理程序
