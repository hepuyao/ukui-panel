#ifndef UKUIPANEL_H
#define UKUIPANEL_H
#include <QFrame>
#include <QtDebug>
#include "panelpluginsmodel.h"
#include <LXQt/Settings>
#include "ilxqtpanel.h"
#include <QMenu>
#include <QPointer>
#include <QTimer>
#include <QRect>
#include <QPropertyAnimation>
#include "panel/ukuipanellayout.h"
#include "panel/lxqtpanellimits.h"

#define CFG_KEY_PLUGINS            	"plugins"
#define PLUGIN_DESKTOPS_DIR		"/usr/share/lxqt/lxqt-panel/"   //临时位置，后面要获取安装目录 set(PLUGIN_DESKTOPS_DIR \"${CMAKE_INSTALL_FULL_DATAROOTDIR}/lxqt/${PROJECT}\")
#define PLUGIN_DESKTOPS_LOCAL_DIR "/usr/local/share/lxqt/lxqt-panel/"

class Plugin;
class ILXQtPanel;
class PanelPluginsModel;
class WindowNotifier;
class ConfigPanelDialog;
class UkuiPanel : public QFrame, public ILXQtPanel
{
    Q_OBJECT

    friend class PanelPluginsModel;

public:
    enum Alignment {
        AlignmentLeft   = -1, //!< Align the panel to the left or top
        AlignmentCenter =  0, //!< Center the panel
        AlignmentRight  =  1 //!< Align the panel to the right or bottom
    };

public:
        UkuiPanel(const QString &configGroup,LXQt::Settings *settings);
        ~UkuiPanel();
        /*show menu*/
        void showUkuiMenu(Plugin *plugin = 0);

        void saveSettings(bool _bVar = false);

        static bool canPlacedOn(int screenNum, UkuiPanel::Position position);

        /*ui parameter set*/
        // Settings
        int panelSize() const { return mPanelSize; }
        int length() const { return mLength; }
        bool lengthInPercents() const { return mLengthInPercents; }
        //LXQtPanel::Alignment alignment() const { return mAlignment; }
        int screenNum() const { return mScreenNum; }
        QColor fontColor() const { return mFontColor; }
        QColor backgroundColor() const { return mBackgroundColor; }
        QString backgroundImage() const { return mBackgroundImage; }
        int opacity() const { return mOpacity; }
        int reserveSpace() const { return mReserveSpace; }
        bool hidable() const { return mHidable; }
        bool visibleMargin() const { return mVisibleMargin; }
        int animationTime() const { return mAnimationTime; }
        int showDelay() const { return mShowDelayTimer.interval(); }
        void realign();
        /*set panel attribute*/
        void setPanelSize(int value, bool save);
        void setIconSize(int value, bool save); //!< \sa setPanelSize()
        void setLineCount(int value, bool save); //!< \sa setPanelSize()
        void setLength(int length, bool inPercents, bool save); //!< \sa setPanelSize()
        void setPosition(int screen, ILXQtPanel::Position position, bool save); //!< \sa setPanelSize()
        void setAlignment(UkuiPanel::Alignment value, bool save); //!< \sa setPanelSize()
        void setFontColor(QColor color, bool save); //!< \sa setPanelSize()
        void setBackgroundColor(QColor color, bool save); //!< \sa setPanelSize()
        void setBackgroundImage(QString path, bool save); //!< \sa setPanelSize()
        void setOpacity(int opacity, bool save); //!< \sa setPanelSize()
        void setReserveSpace(bool reserveSpace, bool save); //!< \sa setPanelSize()
        void setHidable(bool hidable, bool save); //!< \sa setPanelSize()
        void setVisibleMargin(bool visibleMargin, bool save); //!< \sa setPanelSize()
        void setAnimationTime(int animationTime, bool save); //!< \sa setPanelSize()
        void setShowDelay(int showDelay, bool save); //!< \sa setPanelSize()
        void setIconTheme(const QString& iconTheme);
        void updateStyleSheet();

         void updateConfigDialog() const;

        bool isPluginSingletonAndRunnig(QString const & pluginId) const;
        void pluginFlagsChanged(const ILXQtPanelPlugin * plugin);

        /*override from ilxqt class begin*/
        // ILXQtPanel overrides ........
        int iconSize() const override { return mIconSize; } //!< Implement ILXQtPanel::iconSize().
        int lineCount() const  override{ return mLineCount; } //!< Implement ILXQtPanel::lineCount().
        ILXQtPanel::Position position() const override { return mPosition; }

        QRect calculatePopupWindowPos(QPoint const & absolutePos, QSize const & windowSize) const override;
        QRect calculatePopupWindowPos(const ILXQtPanelPlugin *plugin, const QSize &windowSize) const override;
        QRect globalGeometry()const override;
        void willShowWindow(QWidget * w) override;
        //end
        QScopedPointer<PanelPluginsModel> mPlugins;
signals:
    /**
     * @brief This signal gets emitted whenever this panel receives a
     * QEvent::LayoutRequest, i.e. "Widget layout needs to be redone.".
     * The PanelPluginsModel will connect this signal to the individual
     * plugins so they can realign, too.
     */
    void realigned();
    void pluginRemoved();
    void deletedByUser(UkuiPanel *self);
    void pluginAdded();

 public slots:
        void showConfigDialog();
        void showAddPluginDialog();
        void show();
        void hidePanel();
public:
        LXQt::Settings *settings() const { return mSettings; }
        UkuiPanel::Alignment alignment() const { return mAlignment; }
        void pluginMoved(Plugin * plug);

protected:
	bool event(QEvent *event);
	void showEvent(QShowEvent *event) ;
private :
	QString mConfigGroup;

	void loadPlugins();

        void setPanelGeometry(bool animate = false);

	QStringList pluginDesktopDirs();

	LXQt::Settings *mSettings;

        int mPanelSize;

        int mIconSize;

        int mLineCount;

        int mLength;

        bool mLengthInPercents;

        Alignment mAlignment;

        ILXQtPanel::Position mPosition;

        int mScreenNum;

        int mActualScreenNum;

        QTimer mDelaySave;

        bool mHidable;

        bool mVisibleMargin;

        bool mHidden;

        QTimer mHideTimer;

        int mAnimationTime;

        QTimer mShowDelayTimer;

        QColor mFontColor; //!< Font color that is used in the style sheet.
        QColor mBackgroundColor; //!< Background color that is used in the style sheet.
        QString mBackgroundImage; //!< Background image that is used in the style sheet.

        int mOpacity;

        bool mReserveSpace;

        QPointer<ConfigPanelDialog> mConfigDialog;


        QPropertyAnimation *mAnimation;

        bool mLockPanel;

        UkuiPanelLayout* mLayout;

        QScopedPointer<WindowNotifier> mStandaloneWindows;

        QFrame *mUkuiPanelWidget;
        void setMargins();


private slots:
        //void setPanelGeometry();
	void updateWmStrut();
};
#endif // UKUIPANEL_H
