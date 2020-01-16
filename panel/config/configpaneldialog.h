/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * UKUi - a lightweight, Qt based, desktop toolset
 * https://ukui.org
 *
 * Copyright: 2010-2011 Razor team
 * Authors:
 *   Marat "Morion" Talipov <morion.self@gmail.com>
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */

#ifndef CONFIGPANELDIALOG_H
#define CONFIGPANELDIALOG_H

#include "configpanelwidget.h"
#include "configpluginswidget.h"
#include "../ukuipanel.h"

//#include <UKUi/ConfigDialog>
#include "../common/ukuiconfigdialog.h"

class ConfigPanelDialog : public UKUi::ConfigDialog
{
    Q_OBJECT

public:
    ConfigPanelDialog(UKUIPanel *panel, QWidget *parent = 0);

    //this three funtion influnce nothing
    void showConfigPanelPage();
    void showConfigPluginsPage();
    void updateIconThemeSettings();

private:
    ConfigPanelWidget *mPanelPage;
    ConfigPluginsWidget *mPluginsPage;

public slots:
    //void testpaneldig();
public slots:
    void configPosition_top();
    void configPosition_bottom();
    void configPosition_left();
    void configPosition_right();
    void configPanelSize_m();
    void configPanelSize_l();
    void configPanelSize_S();
    void backgroundChange();

signals:
    void testsig();
};

#endif // CONFIGPANELDIALOG_H
