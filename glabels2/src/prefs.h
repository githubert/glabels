/*
 *  (GLABELS) Label and Business Card Creation program for GNOME
 *
 *  prefs.h:  Application preferences module header file
 *
 *  Copyright (C) 2001-2002  Jim Evins <evins@snaught.com>.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 */
#ifndef __PREFS_H__
#define __PREFS_H__

#include <gtk/gtk.h>
#include <libgnomeprint/gnome-font.h>

G_BEGIN_DECLS

typedef struct _glPreferences glPreferences;

typedef enum {
	GL_TOOLBAR_SYSTEM = 0,
	GL_TOOLBAR_ICONS,
	GL_TOOLBAR_ICONS_AND_TEXT
} glToolbarSetting;

typedef enum {
	GL_PREFS_UNITS_PTS,
	GL_PREFS_UNITS_INCHES,
	GL_PREFS_UNITS_MM,
} glPrefsUnits;

struct _glPreferences
{
	/* Units */
	glPrefsUnits      units;

	/* Page size */
	gchar            *default_page_size;

	/* Text properties */
	gchar            *default_font_family;
	gdouble           default_font_size;
	GnomeFontWeight   default_font_weight;
	gboolean          default_font_italic_flag;
	guint             default_text_color;
	GtkJustification  default_text_alignment;
	
	/* Line properties */
	gdouble           default_line_width;
	guint             default_line_color;
	
	/* Fill properties */
	guint             default_fill_color;

	/* User Interface/Main Toolbar */
	gboolean	  main_toolbar_visible;
	glToolbarSetting  main_toolbar_buttons_style; 
	gboolean	  main_toolbar_view_tooltips;

	/* User Interface/Drawing Toolbar */
	gboolean          drawing_toolbar_visible;
	glToolbarSetting  drawing_toolbar_buttons_style; 
	gboolean	  drawing_toolbar_view_tooltips;

	/* View properties */
	gboolean          grid_visible;
	gboolean          markup_visible;

	/* Recent files */
	gint              max_recents;
};

glPreferences *gl_prefs;

void          gl_prefs_save_settings       (void);

void          gl_prefs_load_settings       (void);

void          gl_prefs_init                (void);


const gchar  *gl_prefs_get_page_size       (void);

glPrefsUnits  gl_prefs_get_units           (void);

const gchar  *gl_prefs_get_units_string    (void);

gdouble       gl_prefs_get_units_per_point (void);

gdouble       gl_prefs_get_units_step_size (void);

gint          gl_prefs_get_units_precision (void);

G_END_DECLS

#endif /* __PREFS_H__ */

