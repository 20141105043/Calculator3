
// caculater001Dlg.h : 头文件
//

#pragma once


// Ccaculater001Dlg 对话框
class Ccaculater001Dlg : public CDialogEx
{
// 构造
public:
	Ccaculater001Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CACULATER001_DIALOG };
	CString m_string;
	void SaveValue();
	void Calculator();
	double m_num1;
	double m_num2;
	int flag;
	double c;
	int m_hour;
	int m_min;
	int m_sec;
	double x,y;
	double hourag,minag,secag;

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClicked1();
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedSub();
	afx_msg void OnBnClickedMul();
	afx_msg void OnBnClickedDiv();
	afx_msg void OnBnClickedPoint();
	afx_msg void OnBnClickedBackspace();
    afx_msg void OnBnClickedSqur();
    afx_msg void OnClickedClear();
	afx_msg void OnClickedValue();
	afx_msg void OnBnClickedsqu();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedSqr();
};


