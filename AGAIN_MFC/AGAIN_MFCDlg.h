
// AGAIN_MFCDlg.h : 头文件
//

#pragma once


// CAGAIN_MFCDlg 对话框
class CAGAIN_MFCDlg : public CDialogEx
{
// 构造
public:
	CAGAIN_MFCDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AGAIN_MFC_DIALOG };
#endif

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
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit5();
	// 算式
	CString equation;
	// 用户答案
	int answer;
	// 提示
	CString tip;
	// 答对题数
	int R;
	// 错误
	int W;
	afx_msg void OnBnClickedButton1();
};
