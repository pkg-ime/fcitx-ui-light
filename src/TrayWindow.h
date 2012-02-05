/***************************************************************************
 *   Copyright (C) 2002~2010 by Yuking                                     *
 *   yuking_net@sohu.com                                                   *
 *   Copyright (C) 2010~2010 by CSSlayer                                   *
 *   wengxt@gmail.com                                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/

#include "fcitx/fcitx.h"

#ifndef _TRAY_WINDOW_H
#define _TRAY_WINDOW_H

#include <X11/Xlib.h>
#include <string.h>
#include <X11/Xutil.h>
#include "fcitx-config/fcitx-config.h"
#include <X11/Xdefs.h>

#define INACTIVE_ICON 0
#define ACTIVE_ICON   1
struct _FcitxLightUI;

typedef struct _TrayWindow {
    Window window;

    XImage* icon[2];
    Pixmap picon[2];
    GC gc;
    boolean bTrayMapped;
    XVisualInfo visual;
    Atom atoms[6];
    int size;
    struct _FcitxLightUI* owner;
    Window dockWindow;
} TrayWindow;

TrayWindow* CreateTrayWindow(struct _FcitxLightUI *lightui);
void DrawTrayWindow(TrayWindow* trayWindow);
void DeInitTrayWindow(TrayWindow *f_tray);
void RedrawTrayWindow(TrayWindow* trayWindow);
void ReleaseTrayWindow(TrayWindow* trayWindow);
#endif

// kate: indent-mode cstyle; space-indent on; indent-width 0;
