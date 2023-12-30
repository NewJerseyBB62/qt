#include "logindialog.h"
#include "ui_logindialog.h"
#include <QtWinExtras/QtWinExtras>
#include <windows.h>

#if 0
enum AccentState
{
        ACCENT_DISABLED = 0,
        ACCENT_ENABLE_GRADIENT = 1,
        ACCENT_ENABLE_TRANSPARENTGRADIENT = 2,
        ACCENT_ENABLE_BLURBEHIND = 3,
        ACCENT_INVALID_STATE = 4
};

struct AccentPolicy
{
        AccentState AccentState;
        int AccentFlags;
        int GradientColor;
        int AnimationId;
};

enum WindowCompositionAttribute
{
        WCA_UNDEFINED = 0,
        WCA_NCRENDERING_ENABLED = 1,
        WCA_NCRENDERING_POLICY = 2,
        WCA_TRANSITIONS_FORCEDISABLED = 3,
        WCA_ALLOW_NCPAINT = 4,
        WCA_CAPTION_BUTTON_BOUNDS = 5,
        WCA_NONCLIENT_RTL_LAYOUT = 6,
        WCA_FORCE_ICONIC_REPRESENTATION = 7,
        WCA_EXTENDED_FRAME_BOUNDS = 8,
        WCA_HAS_ICONIC_BITMAP = 9,
        WCA_THEME_ATTRIBUTES = 10,
        WCA_NCRENDERING_EXILED = 11,
        WCA_NCADORNMENTINFO = 12,
        WCA_EXCLUDED_FROM_LIVEPREVIEW = 13,
        WCA_VIDEO_OVERLAY_ACTIVE = 14,
        WCA_FORCE_ACTIVEWINDOW_APPEARANCE = 15,
        WCA_DISALLOW_PEEK = 16,
        WCA_CLOAK = 17,
        WCA_CLOAKED = 18,
        WCA_ACCENT_POLICY = 19,
        WCA_FREEZE_REPRESENTATION = 20,
        WCA_EVER_UNCLOAKED = 21,
        WCA_VISUAL_OWNER = 22,
        WCA_LAST = 23
};

struct WCAD
{
        WindowCompositionAttribute Attribute;
        int * Data;
        int SizeOfData;
};

typedef int* (*pfun)(HWND hwnd, WCAD *data);
#endif

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->showFullScreen();
    ui->registBtn->setVisible(false);

//    if (QtWin::isCompositionEnabled()) {
//           QtWin::extendFrameIntoClientArea(this, -1, -1, -1, -1);
//           this->setAttribute(Qt::WA_TranslucentBackground, true);
//           this->setAttribute(Qt::WA_NoSystemBackground, false);
//           this->setStyleSheet("MainWindow { background: transparent; }");
//       } else {
//           QtWin::resetExtendedFrame(ui->loginWidget);
//           ui->loginWidget->setAttribute(Qt::WA_TranslucentBackground, false);
//           setStyleSheet(QString("MainWindow { background: %1; }")
//                         .arg(QtWin::realColorizationColor().name()));
//       }

//    HWND hWnd = HWND(ui->loginWidget->winId());
//    HMODULE hUser = GetModuleHandle(L"user32.dll");
//    if (hUser) {
//        pfun setWindowCompositionAttribute = (pfun)GetProcAddress(hUser, "SetWindowCompositionAttribute");
//        if (setWindowCompositionAttribute) {
//            AccentPolicy accent = {ACCENT_ENABLE_BLURBEHIND, 0, 0, 0};//ACCENT_ENABLE_BLURBEHIND 具体枚举参加MSDN
//            WCAD data;
//            data.Attribute = WCA_ACCENT_POLICY;//WCA_ACCENT_POLICY 具体枚举参加MSDN
//            data.Data = reinterpret_cast<int *>(&accent) ;
//            data.SizeOfData = sizeof(accent);
//            setWindowCompositionAttribute(hWnd, &data);
//        }
//    }
//    this->setAttribute(Qt::WA_TranslucentBackground);
//    ui->loginWidget->setAttribute(Qt::WA_TranslucentBackground);
}

loginDialog::~loginDialog()
{
    delete ui;
}


void loginDialog::on_loginBtn_clicked()
{
    done(Accepted);
    close();
}

void loginDialog::on_minBtn_clicked()
{
    this->showMinimized();
}

void loginDialog::on_closeBtn_clicked()
{
    done(Rejected);
    close();
}
