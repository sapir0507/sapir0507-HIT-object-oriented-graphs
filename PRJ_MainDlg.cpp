
// PRJ_MainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_PRJ_FINAL.h"
#include "PRJ_MainDlg.h"
#include "afxdialogex.h"





#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// PRJ_MainDlg dialog




PRJ_MainDlg::PRJ_MainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(PRJ_MainDlg::IDD, pParent)
	, Graph_type(0)
	, Graph_size(0)
	, previndex(-1)
	, undo_count(0)
{
	color = RGB(0,0,0);
	Lispressed=false;
	Rispressed=false;
	Chosen=false;

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void PRJ_MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Graph_size);
	DDV_MinMaxInt(pDX, Graph_size, 1, 50);
}

BEGIN_MESSAGE_MAP(PRJ_MainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_RADIO1, &PRJ_MainDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO3, &PRJ_MainDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &PRJ_MainDlg::OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_BUTTON2, &PRJ_MainDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &PRJ_MainDlg::OnBnClickedButton1)
	
	ON_BN_CLICKED(IDC_BUTTON3, &PRJ_MainDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &PRJ_MainDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &PRJ_MainDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &PRJ_MainDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &PRJ_MainDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &PRJ_MainDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// PRJ_MainDlg message handlers

BOOL PRJ_MainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void PRJ_MainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void PRJ_MainDlg::OnPaint()
{
	
	CPaintDC dc(this);
	
	CRect pallete;					//for beautiful white pallete to draw on
	GetClientRect(pallete);
	pallete.SetRect(pallete.BottomRight().x-10, pallete.BottomRight().y-10, pallete.TopLeft().x+10, pallete.TopLeft().y+120);
	dc.Rectangle(pallete);
	
	CBrush col(color);				//for nice little colorful rectangle under "choose color" button
	CRect colorRec(135,75,190,90);
	dc.FillRect(colorRec, &col);

	for(int i=0 ; i<G.GetSize() ; i++)
	{
		G.GetAt(i)->PrintGraph(&dc);
	}
	

	CDialogEx::OnPaint();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR PRJ_MainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void PRJ_MainDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	

	SetCursor(LoadCursor(NULL, IDC_CROSS));
	Lispressed = true;
	
	for(int i=0 ; i<G.GetSize() ; i++)
	{
		if(G.GetAt(i)->isonaGraph(point))
		{	
			previndex = i;
			G.GetAt(i)->MarkGraph(&dc);
			return;
		}
	}
	previndex=-1;
	Invalidate();
	
	CDialogEx::OnLButtonDown(nFlags, point);
}


void PRJ_MainDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	Lispressed=false;
	
	Invalidate();

	CDialogEx::OnLButtonUp(nFlags, point);
}


void PRJ_MainDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnRButtonDown(nFlags, point);
}

void PRJ_MainDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CDialogEx::OnRButtonUp(nFlags, point);
}


void PRJ_MainDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	if(Lispressed == true && previndex >= 0)
	{	
		SetCursor(LoadCursor(NULL, IDC_CROSS));
		G.GetAt(previndex)->setcenterp(point);
		G.GetAt(previndex)->buildgraph();
		dc.SetROP2(R2_XORPEN);
		G.GetAt(previndex)->PrintGraph(&dc);
		G.GetAt(previndex)->PrintGraph(&dc);
	}
	
	for(int i=0 ; i<G.GetSize() ; i++)
	{

		if(G.GetAt(i)->isonaGraph(point))
		{
			SetCursor(LoadCursor(NULL, IDC_HAND));
		}
	}

	CDialogEx::OnMouseMove(nFlags, point);
}


void PRJ_MainDlg::OnBnClickedRadio1()
{
	//choose Kn Graph
	Graph_type=1;
}
void PRJ_MainDlg::OnBnClickedRadio3()
{
	//choose Cn Graph
	Graph_type=2;
}
void PRJ_MainDlg::OnBnClickedRadio4()
{
	//choose BT Graph
	Graph_type=3;

}


void PRJ_MainDlg::OnBnClickedButton2()
{
	//Choose color dialog pops up

	CClientDC dc(this);
	
	CColorDialog dlg; 
	if (dlg.DoModal() == IDOK) 
		 color = dlg.GetColor(); 

	Invalidate();
}


void PRJ_MainDlg::OnBnClickedButton1()
{
	// DRAW! Button , draw Graph with selected properties:
	CPoint p;
	CRect rec;
	int mekademx = G.GetSize()%3;
	int mekademy = G.GetSize()/3;

	GetClientRect(rec);

	p.x = rec.CenterPoint().x-400+mekademx*400 ;
	p.y = ( rec.CenterPoint().y-150+mekademy*150 )% rec.bottom;
	
	
	UpdateData(true);
	

	if(Graph_size<=50 && Graph_size>=1)
	{		
		if(Graph_type == 0)
		{
			return;
		}
		if(Graph_type == 1)
		{
			KnGraph *temp;
			temp = new KnGraph(Graph_size, color, p);
			temp->buildgraph();
			G.Add(temp);
		}
		else if(Graph_type == 2)
		{	
			CnGraph *temp;
			temp = new CnGraph(Graph_size, color, p);
			temp->buildgraph();
			G.Add(temp);
		}
		else if(Graph_type == 3)
		{
			BinTreeGraph *temp;
			temp = new BinTreeGraph(Graph_size, color, p);
			temp->buildgraph();
			G.Add(temp);
		}
		
	}	
	Invalidate();
}		

void PRJ_MainDlg::OnBnClickedButton6()
{
	// Clear All Graphs
	G.RemoveAll();
	undo_count=0;
	Invalidate();
}

void PRJ_MainDlg::OnBnClickedButton3()
{
	//Delete Button
	if(previndex>=0)
	{
		K.Push(G.GetAt(previndex));
		G.RemoveAt(previndex);
		previndex =-1;
		Chosen = false;
	}
	Invalidate();
	
}


void PRJ_MainDlg::OnBnClickedButton4()
{

 	//Save:
	LPCTSTR szFilters= _T("Graphs File (*.Graphs)");
	CFileDialog dlg(FALSE, _T("*.Graphs"), _T("*.Graphs"),OFN_OVERWRITEPROMPT, szFilters);
    
	
	if(dlg.DoModal() == IDOK)
	{
		CString filename;
		filename = dlg.GetFileName(); 
        CString filepath = dlg.GetFolderPath(); 
		filepath += _T("\\");
		CFile file(filepath+filename,CFile::modeWrite|CFile::modeCreate);		
		CArchive ar (&file, CArchive::store);
		G.Serialize(ar);
		ar.Close();
		file.Close();
	}
}

void PRJ_MainDlg::OnBnClickedButton5()
{
	// Load File:
	
	LPCTSTR szFilters= _T("Graphs File (*.Graphs)|*.Graphs|") _T("All Files (*.*)|*.*|");
	CFileDialog dlg(TRUE, _T("*.Graphs"), _T("*.Graphs"),OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters, this);
	
	if(dlg.DoModal() == IDOK)
	{
		CString filename;
		filename = dlg.GetFileName(); 
 
		CFile file(filename,CFile::modeRead); 
		CArchive ar(&file, CArchive::load);
		G.Serialize(ar);
		ar.Close();
		file.Close();
		CFileDialog dlg(false);
		Invalidate();
	}
}


void PRJ_MainDlg::OnBnClickedButton7()
{
	//UNDO
	if(K.GetSize()>0)
	{
		G.Add(K.Pop());
		undo_count++;
		Invalidate();
	}
}

void PRJ_MainDlg::OnBnClickedButton8()
{
	//REDO
	if(undo_count>0)
	{
		K.Push(G.GetAt(G.GetSize()-1));
		G.RemoveAt(G.GetSize()-1);
		undo_count--;
		Invalidate();
	}
}
