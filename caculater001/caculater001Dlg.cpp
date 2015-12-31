
// caculater001Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "caculater001.h"
#include "caculater001Dlg.h"
#include "afxdialogex.h"
#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// Ccaculater001Dlg 对话框




Ccaculater001Dlg::Ccaculater001Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ccaculater001Dlg::IDD, pParent)
	, m_string(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	c=180;
}

void Ccaculater001Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_string);
}

BEGIN_MESSAGE_MAP(Ccaculater001Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(IDC_1, &Ccaculater001Dlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &Ccaculater001Dlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &Ccaculater001Dlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &Ccaculater001Dlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &Ccaculater001Dlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &Ccaculater001Dlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &Ccaculater001Dlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &Ccaculater001Dlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &Ccaculater001Dlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_0, &Ccaculater001Dlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_ADD, &Ccaculater001Dlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_SUB, &Ccaculater001Dlg::OnBnClickedSub)
	ON_BN_CLICKED(IDC_MUL, &Ccaculater001Dlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_DIV, &Ccaculater001Dlg::OnBnClickedDiv)
	ON_BN_CLICKED(IDC_Point, &Ccaculater001Dlg::OnBnClickedPoint)
	ON_BN_CLICKED(IDC_Backspace, &Ccaculater001Dlg::OnBnClickedBackspace)
    ON_BN_CLICKED(IDC_Clear, &Ccaculater001Dlg::OnClickedClear)
	ON_BN_CLICKED(IDC_Value, &Ccaculater001Dlg::OnClickedValue)
	ON_BN_CLICKED(IDC_squ, &Ccaculater001Dlg::OnBnClickedsqu)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_Sqr, &Ccaculater001Dlg::OnBnClickedSqr)
END_MESSAGE_MAP()


// Ccaculater001Dlg 消息处理程序

BOOL Ccaculater001Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetTimer(1,1000,NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Ccaculater001Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Ccaculater001Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Ccaculater001Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void Ccaculater001Dlg::OnBnClicked1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"1";
	UpdateData(false);
}   

void Ccaculater001Dlg::OnBnClicked2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"2";
	UpdateData(false);
}

void Ccaculater001Dlg::OnBnClicked3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"3";
	UpdateData(false);
}

void Ccaculater001Dlg::OnBnClicked4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"4";
	UpdateData(false);
}

void Ccaculater001Dlg::OnBnClicked5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"5";
	UpdateData(false);
}

void Ccaculater001Dlg::OnBnClicked6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"6";
	UpdateData(false);
}

void Ccaculater001Dlg::OnBnClicked7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"7";
	UpdateData(false);
}

void Ccaculater001Dlg::OnBnClicked8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"8";
	UpdateData(false);
}

void Ccaculater001Dlg::OnBnClicked9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"9";
	UpdateData(false);
}

void Ccaculater001Dlg::OnBnClicked0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string=m_string+L"0";
	UpdateData(false);
}

void Ccaculater001Dlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveValue();
	flag=0;
}

void Ccaculater001Dlg::OnBnClickedSub()
{
	// TODO: 在此添加控件通知处理程序代码
    SaveValue();
	flag=1;
}

void Ccaculater001Dlg::OnBnClickedMul()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveValue();
	flag=2;
}

void Ccaculater001Dlg::OnBnClickedDiv()
{
	// TODO: 在此添加控件通知处理程序代码
	SaveValue();
	flag=3;
}

void Ccaculater001Dlg::OnBnClickedPoint()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(-1==m_string.Find(L"."));
	m_string=m_string+L".";
	UpdateData(false);
}
void Ccaculater001Dlg::OnBnClickedsqu()
{
	// TODO: 在此添加控件通知处理程序代码
    UpdateData(true);  
    m_num1 = _ttof(m_string);  
    double f = m_num1 * m_num1;  
    //如果浮点数其实是个整数   
    if(f - int(f) <= 1e-5)  
    {  
        m_string.Format(L"%d",(int)f);  
    }  
    else  
    {  
        m_string.Format(L"%f",f);  
    }  
    UpdateData(FALSE);  
    m_num1 = f;  
    m_num2 = 0.0f;  
    flag = 4;  
}
void Ccaculater001Dlg::OnBnClickedSqr()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);  
    m_num1 = _ttof(m_string);  
    double f = sqrt(m_num1);  
    //如果浮点数其实是个整数   
    if(f - int(f) <= 1e-5)  
    {  
         m_string.Format(L"%d",(int)f);  
    }  
    else  
    {  
         m_string.Format(L"%f",f);  
    }  
    UpdateData(FALSE);  
    m_num1 = f;  
    m_num2 = 0.0f;  
    flag = 5;
}


void Ccaculater001Dlg::OnBnClickedBackspace()
{
	// TODO: 在此添加控件通知处理程序代码 
    if(!m_string.IsEmpty()) 
    { 
        m_string=m_string.Left(m_string.GetLength()-1); 
    } 
    UpdateData(false);
}




void Ccaculater001Dlg::OnClickedClear()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_string="";
	m_num1=0.0f;
	m_num2=0.0f;
	flag=0;
	UpdateData(false);
}


void Ccaculater001Dlg::OnClickedValue()
{
	// TODO: 在此添加控件通知处理程序代码
	Calculator(); 
}
void Ccaculater001Dlg::SaveValue()  
{  
    UpdateData(true);  
    m_num1 = _ttof(m_string);  
    m_string = "";  
    UpdateData(false);  
} 
void Ccaculater001Dlg::Calculator()  
{  
    UpdateData(true);  
    m_num2 = _ttof(m_string);  
    double f = 0.0f;  
    switch (flag)
	{  
          
     case 0:  
        f = m_num1 + m_num2;  
        break;  
           
     case 1:  
        f = m_num1 - m_num2;  
        break;  
          
     case 2:  
        f = m_num1 * m_num2;  
        break;  
         
     case 3:
		
        if (fabs(m_num2)<0.001)  
        {  
           f = m_num1;  
        }  
        else  
        {  
           f = m_num1 / m_num2;  
        }  
        break;  
         
     case 4:  
        f = m_num2 * m_num2;  
        break;  
          
     case 5:  
        f = sqrt(m_num2);  
        break;  
     default:  
        break;  
    }  
      
   if(f - int(f) <= 1e-5)  
   {  
       m_string.Format(L"%d",(int)f);  
   }  
    else  
    {  
       m_string.Format(L"%f",f);  
    }  
    UpdateData(false);  
 
    m_num1 = f;  
    m_num2 = 0.0f;  
} 




void Ccaculater001Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
    int L1=45,L2=40,L3=25;
    CTime t;
	t=CTime::GetCurrentTime();
	m_hour=t.GetHour();
	m_min=t.GetMinute();
	m_sec=t.GetSecond();
	UpdateData(false);
	CClientDC dc(this);
	dc.SetWindowOrg(-285,-180);
	CPen *oldpen;
	CPen whitepen(PS_SOLID,4,RGB(255,255,255));
	CPen pen (PS_SOLID,3,RGB(0,0,0));
	oldpen=dc.SelectObject(&pen);
	dc.Ellipse(-50,50,50,-50);
	CPen ppen (PS_SOLID,8,RGB(0,0,0));
	oldpen=dc.SelectObject(&ppen);
	/*for(int i=0;i<12;i++)
	{
		double l=96,ag=i*3.1415926/6;
		double a=l*sin(ag)+1,b=-l*cos(ag)+1,c=l*sin(ag)-1,d=-1*cos(ag)-1;
		dc.Ellipse(a,b,c,d);
	}*/
	/*dc.TextOutW(-8,-50,L"12");
	dc.TextOutW(80,-8,L"3");
	dc.TextOutW(-4,76,L"6");
	dc.TextOutW(-86,-8,L"9");*/
	oldpen=dc.SelectObject(&whitepen);
	secag=m_sec*(3.1415926/30);
	x=L1*sin(secag);
	y=-L1*cos(secag);
	dc.MoveTo(0,0);
	dc.LineTo(x,y);
	CPen secpen(PS_SOLID,2,RGB(150,150,150));
	oldpen=dc.SelectObject(&secpen);
	secag=secag+3.1415926/30;
	x=L1*sin(secag);
	y=-L1*cos(secag);
	dc.MoveTo(0,0);
	dc.LineTo(x,y);
	if(secag>=6.2831852)
		secag=-3.1415926/30;
	oldpen=dc.SelectObject(&whitepen);
	minag=m_min*(3.1415926/30)+m_sec*(3.1415926/1800);
	x=L2*sin(minag);
	y=-L2*cos(minag);
	dc.MoveTo(0,0);
	dc.LineTo(x,y);
	if(minag>=6.2831852)
		minag=-3.1415926/1800;
	oldpen=dc.SelectObject(&whitepen);
	hourag=m_hour*(3.1415926/6)+m_min*(3.1415926/360)+m_sec*(3.1415826/21600);
	x=L3*sin(hourag);
	y=-L3*cos(hourag);
	dc.MoveTo(0,0);
	dc.LineTo(x,y);
	CPen hourpen(PS_SOLID,3.5,RGB(50,50,50));
	oldpen=dc.SelectObject(&hourpen);
	hourag=hourag+3.1415926/21600;
	x=L3*sin(hourag);
	y=-L3*cos(hourag);
	dc.MoveTo(0,0);
	dc.LineTo(x,y);
	if(hourag>=6.2831852)
		hourag=-3.1415926/21600;
	
	/*int r=40,x,y,ox=100,oy=100;
	CDC *pDC;
	pDC=GetDC();
	x=ox+r*sin(c*3.1415926/180);
	y=oy+r*cos(c*3.1415926/180);
	pDC->MoveTo(ox,oy);
	pDC->LineTo(x,y);
	c=c-6;*/

	CDialogEx::OnTimer(nIDEvent);
}

