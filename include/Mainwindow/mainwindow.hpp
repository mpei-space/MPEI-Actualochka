#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "include/General/general.hpp"
#include "include/General/configerexplorer.hpp"
#include "include/System/usystemtray.hpp"
#include "include/System/utimerhandler.hpp"
#include "include/System/uwebhandler.hpp"
#include "include/System/serverjsonparser.hpp"
#include "include/System/calendardatehandler.hpp"
#include "include/System/contentfileio.hpp"
#include "include/UI/switchbutton.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    virtual void keyPressEvent(QKeyEvent *event) final;

    void InitWindowParameters();

public slots:
    void onResultCheckForUpdate(QNetworkReply *reply);
    void onAutoRunChanged(int state);
    void onNotifyChanged(int state);
    void onDarkThemeChanged(int state);
    void onComboBoxActivated(int index);
    void onSpinBoxValueChanged(int value);
    void onSysTrayActivated(QSystemTrayIcon::ActivationReason reason);

private:
    void InitPrivateParameters();
    void SetUpSettingsTab();
    void SetUpConnects();
    void MakeReceive();
    void ConnectOnlineSlots();

signals:
    void quitapp();
    void newversion();

private:
    Content content;
    ThemeManager manager;
    ContentFileIO contentManager;

    SwitchButton        *swButton   = nullptr;
    CalendarDateHandler *calendar   = nullptr;
    ConfigerExplorer    *config     = nullptr;
    USystemTray         *sysTray    = nullptr;
    UTimerHandler       *timer      = nullptr;
    UWebHandler         *web        = nullptr;
    Ui::MainWindow      *ui         = nullptr;

};
#endif // MAINWINDOW_HPP
