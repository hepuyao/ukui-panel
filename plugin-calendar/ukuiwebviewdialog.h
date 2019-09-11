﻿#ifndef UKUIWEBVIEWDIALOG_H
#define UKUIWEBVIEWDIALOG_H

#include <QDialog>
#include <QtWebKitWidgets/QWebView>
#include <QtWebKitWidgets/QWebFrame>
#include "../panel/iukuipanelplugin.h"
namespace Ui {
class UkuiWebviewDialog;
}

class UkuiWebviewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UkuiWebviewDialog(QWidget *parent = nullptr);
    ~UkuiWebviewDialog();
    void creatwebview();
    void showinfo(QString string);
    QWebView   *mWebView;
signals:
    void deactivated();

private:
    Ui::UkuiWebviewDialog *ui;
    QSize      mQsize;
protected:
    virtual bool event(QEvent *event);
};

#endif // UKUIWEBVIEWDIALOG_H
