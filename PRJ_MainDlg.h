#include "Graph.h"
#include "cngraph.h"
#include"KnGraph.h"
#include "BinTreeGraph.h"
#include "Stack.h"
// PRJ_MainDlg.h : header file
//

#pragma once


// PRJ_MainDlg dialog
class PRJ_MainDlg : public CDialogEx
{
private:
	
	CStack K;
	CTypedPtrArray<CObArray,Graph*> G;
	int previndex;
	int Graph_size;
	int Graph_type;
	bool Lispressed, Rispressed, Chosen;
	COLORREF color;
	unsigned int undo_count;
// Construction
public:
	PRJ_MainDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFC_PRJ_FINAL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	
	
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();

	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();

};
