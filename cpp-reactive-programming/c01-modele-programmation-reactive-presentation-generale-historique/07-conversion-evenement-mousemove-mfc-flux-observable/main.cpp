#include "stdafx.h"
#include <afxwin.h>
#include <afxext.h>
#include <math.h>
#include <vector>
#include "../Common2.h"
using namespace std;
class CMouseFrame : public CFrameWnd, IObservable<CPoint>
{
private:
    RECT _rect;
    POINT _curr_pos;
    vector<IObserver<CPoint> *> _event_src;

public:
    CMouseFrame()
    {
        HBRUSH brush = (HBRUSH)::CreateSolidBrush(
            RGB(175, 238, 238));
        CString mywindow = AfxRegisterWndClass(
            CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS, 0, brush, 0);
        Create(mywindow, _T("Horloge MFC par Praseed Pai"));
    }

    virtual bool Subscribe(IObserver<CPoint> &observer)
    {
        _event_src.push_back(&observer);
        return true;
    }

    bool FireEvent(const CPoint &pt)
    {
        vector<IObserver<CPoint> *>::iterator it =
            _event_src.begin();
        while (it != _event_src.end())
        {
            IObserver<CPoint> *observer = *it;
            observer->OnNext(pt);
            observer->OnCompleted();
            it++;
        }
        return true;
    }

    int OnCreate(LPCREATESTRUCT l)
    {
        return CFrameWnd::OnCreate(l);
    }

    void SetCurrentPoint(CPoint pt)
    {
        this->_curr_pos = pt;
        Invalidate(0);
    }

    void OnPaint()
    {
        CPaintDC d(this);
        CBrush b(RGB(100, 149, 237));
        int x1 = -200, y1 = -220, x2 = 210, y2 = 200;
        Transform(&x1, &y1);
        Transform(&x2, &y2);
        // ... CRect rect(x1, y1, x2, y2);
        d.FillRect(&rect, &b);
        CPen p2(PS_SOLID, 2, RGB(153, 0, 0));
        d.SelectObject(&p2);
        char *str = "Hello Reactive C++";
        CFont f;
        f.CreatePointFont(240, _T("Times New Roman"));
        d.SelectObject(&f);
        d.SetTextColor(RGB(204, 0, 0));
        d.SetBkMode(TRANSPARENT);
        CRgn crgn;
        crgn.CreateRectRgn(rect.left, rect.top, rect.right, rect.bottom);
        d.SelectClipRgn(&crgn);
        d.TextOut(_curr_pos.x, _curr_pos.y, CString(str), strlen(str));
    }

    void Transform(int *px, int *py)
    {
        ::GetClientRect(m_hWnd, &_rect);
        int width = (_rect.right - _rect.left) / 2;
        int height = (_rect.bottom - _rect.top) / 2;
        *px += width;
        *py = height - *py;
    }

    void OnMouseMove(UINT nFlags, CPoint point)
    {
        int x1 = -200, y1 = -220, x2 = 210, y2 = 200;
        Transform(&x1, &y1);
        Transform(&x2, &y2);
        CRect rect(x1, y1, x2, y2);
        POINT pts;
        pts.x = point.x;
        pts.y = point.y;
        rect.NormalizeRect();

        if (rect.PtInRect(point))
        {
            FireEvent(point);
        }
    }

    DECLARE_MESSAGE_MAP();
};
DEBUT_TABLE_MESSAGES(CMouseFrame, CFrameWnd)
ON_WM_CREATE()
ON_WM_PAINT()
ON_WM_MOUSEMOVE()
FIN_TABLE_MESSAGES()

class WindowHandler : public IObserver<CPoint>
{
private:
    CMouseFrame *fenetre;

public:
    WindowHandler(CMouseFrame *win) : fenetre(win) {}
    virtual ~WindowHandler() { fenetre = 0; }
    virtual void OnCompleted() {}
    virtual void OnError(CustomException *exception) {}
    virtual void OnNext(CPoint value)
    {
        if (fenetre)
            fenetre->SetCurrentPoint(value);
    }
};

class CMouseApp : public CWinApp
{
    WindowHandler *gestionnaire_evenements;

public:
    int InitInstance()
    {
        CMouseFrame *p = new CMouseFrame();
        p->ShowWindow(1);
        gestionnaire_evenements = new WindowHandler(p);
        p->Subscribe(*gestionnaire_evenements);
        m_pMainWnd = p;
        return 1;
    }
    virtual ~CMouseApp()
    {
        if (gestionnaire_evenements)
        {
            delete gestionnaire_evenements;
            gestionnaire_evenements = 0;
        }
    }
};

CMouseApp a;