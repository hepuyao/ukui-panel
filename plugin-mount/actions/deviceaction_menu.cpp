/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * LXQt - a lightweight, Qt based, desktop toolset
 * https://lxqt.org
 *
 * Copyright: 2013 Razor team
 * Authors:
 *   Alexander Sokoloff <sokoloff.a@gmail.com>
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

#include "deviceaction_menu.h"
#include "../ukuimountplugin.h"
#include "../popup.h"

DeviceActionMenu::DeviceActionMenu(UKUIMountPlugin *plugin, QObject *parent):
    DeviceAction(plugin, parent)
{
    mPopup = plugin->popup();

    mHideTimer.setSingleShot(true);
    mHideTimer.setInterval(5000);
    connect(&mHideTimer, &QTimer::timeout, mPopup, &Popup::hide);
}

void DeviceActionMenu::doDeviceAdded(Solid::Device device)
{
    mHideTimer.start();
    mPopup->show();
}

void DeviceActionMenu::doDeviceRemoved(Solid::Device device)
{
}
