#ifndef STARTMENU_H
#define STARTMENU_H

#include "../panel/iukuipanelplugin.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QFrame>
#include <QFontMetrics>
#include <QLineEdit>
#include <QToolButton>
#include <XdgIcon>

#include "lxqtmainmenuconfiguration.h"



#include <QMainWindow>
#include <QHBoxLayout>
#include <QDebug>
#include <QProcess>

#include "../panel/plugin.h"
#include "../panel/ukuipanel.h"
#define DEFAULT_SHORTCUT "Alt+F1"


class  StartMenuWidget: public QFrame
{
    Q_OBJECT
public:
    StartMenuWidget(QWidget* parent = nullptr);
    ~StartMenuWidget();

    QLineEdit *lineEdit() { return &mLineEdit; }
    QToolButton *button() { return &mButton; }


protected:
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void captureMouse();

private:
    QLineEdit mLineEdit;
    QToolButton mButton;
    bool mCapturing;
};



class StartMenu : public QObject, public IUKUIPanelPlugin
{
    Q_OBJECT
public:
    StartMenu(const IUKUIPanelPluginStartupInfo &startupInfo);
    ~StartMenu();

    virtual QWidget *widget() { return &m2Widget; }

    virtual QString themeId() const { return QStringLiteral("startmenu"); }

    bool isSeparate() const { return true; }

    void realign();
    virtual IUKUIPanelPlugin::Flags flags() const { return PreferRightAlignment | HaveConfigDialog ; }
    QDialog *configureDialog();
private:
    StartMenuWidget m2Widget;
    GlobalKeyShortcut::Action *mShortcut;
    QTimer mDelayedPopup;
    QTimer mHideTimer;

};

class StartMenuLibrary: public QObject, public IUKUIPanelPluginLibrary
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "lxqt.org/Panel/PluginInterface/3.0")
    Q_INTERFACES(IUKUIPanelPluginLibrary)
public:
    IUKUIPanelPlugin *instance(const IUKUIPanelPluginStartupInfo &startupInfo) const
    {
        return new StartMenu(startupInfo);
    }
};

#endif
