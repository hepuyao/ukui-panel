/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 * UKUi - a lightweight, Qt based, desktop toolset
 * https://ukui.org
 *
 * Copyright (C) 2013  Alec Moskvin <alecm@gmx.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * END_COMMON_COPYRIGHT_HEADER */

#ifndef UKUIPROGRAMFINDER_H
#define UKUIPROGRAMFINDER_H

#include <QStringList>
#include "ukuiglobals.h"

namespace UKUi
{

namespace ProgramFinder
{
    /*!
     * \brief programExists Checks if the program needed to execute the given
     *        command is installed
     * \param command
     * \return True if the program exists
     */
    UKUI_API bool programExists(const QString& command);

    /*!
     * \brief findPrograms Filters a list of commands (with arguments) based on
     *        which programs are installed
     * \param commands Commands to check
     * \return List of commands which are installed
     */
    UKUI_API QStringList findPrograms(const QStringList& commands);

    /*!
     * \brief programName Returns the program name given a command
     * \param command
     * \return
     */
    UKUI_API QString programName(const QString& command);
}

} // namespace UKUi
#endif // UKUIPROGRAMFINDER_H
