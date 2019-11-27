#include<afxwin.h>
class CMainFrame : public CFrameWnd {
public:
  CMainFrame() {
      Create(NULL, L"심재창교수님 사랑합니다 !"); //문구 바꿈
   }
   DECLARE_MESSAGE_MAP()
   afx_msg void OnPaint();
   afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
   afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
   afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};
class CMy : public CWinApp {
   BOOL InitInstance() {
      CMainFrame* Frame = new CMainFrame();
      m_pMainWnd = Frame;
      Frame->ShowWindow(1);
      return TRUE;
   }
};
CMy theApp; BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
ON_WM_PAINT()
ON_WM_LBUTTONDOWN()
ON_WM_RBUTTONDOWN()
ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()
#include<atlimage.h>
void CMainFrame::OnPaint()
{
   CImage img;
   CPaintDC dc(this);
   img.Load(L"jc.png"); //사진 바꿈
   img.Draw(dc, 500, 100);  //사진 위치 바꿈
               

}
void CMainFrame::OnRButtonDown(UINT nFlags, CPoint point) //오른쪽 버튼으로 바꿈
{
   CClientDC dc(this);
   dc.SetTextColor(RGB(255, 0, 0));
   dc.SetBkColor(RGB(192, 192, 192));//배경 색 바꿈
   dc.SetBkMode(TRANSPARENT); 
   dc.TextOut(point.x, point.y, CString("MFC"));//문구 바꿈
   dc.SetBkMode(OPAQUE); 
   dc.TextOut(point.x, point.y + 20, CString("사랑합니다."));//문구 바꿈
   dc.DrawText(CString("MFC"),
      CRect(point.x, point.y, point.x + 50, point.y + 50), DT_TOP | DT_LEFT);
   CFrameWnd::OnLButtonDown(nFlags, point);
}
CPoint pnt;
COLORREF col = RGB(0, 255, 0); //색 바꿈
void CMainFrame::OnMouseMove(UINT nFlags, CPoint point)
{
   if (nFlags == MK_LBUTTON) {
      CClientDC dc(this);
      CPen pen(PS_SOLID, 16, col); // 크기 바꿈
      dc.SelectObject(&pen);
      dc.MoveTo(pnt);
      dc.LineTo(point);
   }
   pnt = point;
   CFrameWnd::OnMouseMove(nFlags, point);
}
