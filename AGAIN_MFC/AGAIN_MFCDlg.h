
// AGAIN_MFCDlg.h : ͷ�ļ�
//

#pragma once


// CAGAIN_MFCDlg �Ի���
class CAGAIN_MFCDlg : public CDialogEx
{
// ����
public:
	CAGAIN_MFCDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AGAIN_MFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit5();
	// ��ʽ
	CString equation;
	// �û���
	int answer;
	// ��ʾ
	CString tip;
	// �������
	int R;
	// ����
	int W;
	afx_msg void OnBnClickedButton1();
};
