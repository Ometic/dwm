/* See LICENSE file for copyright and license details. */

/* Imports */
#include "fibonacci.c"

/* Macros */
#define MODKEY Mod4Mask
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* General */
static const unsigned int borderpx  = 3;
static const unsigned int snap = 32;
static const char *fonts[] = { "Hack Nerd Font:size=12" };

/* Gaps */
static const unsigned int gappih = 10;
static const unsigned int gappiv = 10;
static const unsigned int gappoh = 10;
static const unsigned int gappov = 10;
static const int smartgaps = 0;

/* Bar */
static const int showbar = 0;
static const int topbar = 0;

/* Colors */
static const char col_gray1[] = "#222222";
static const char col_gray2[] = "#444444";
static const char col_gray3[] = "#bbbbbb";
static const char col_gray4[] = "#eeeeee";
static const char col_cyan[] = "#005577";

static const char *colors[][3] = {
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel] = { col_gray4, col_cyan,  col_cyan },
};

/* Workspace */
static const char *tags[] = { "1", "2", "3", "4", "5", "6" };

/* Rules */
static const Rule rules[] = {
	{ "Gimp", NULL, NULL, 0, 1, -1 },
};

/* Layouts */
static const float mfact     = 0.55; 
static const int nmaster     = 1; 
static const int resizehints = 1; 
static const int lockfullscreen = 1; 

static const Layout layouts[] = {
	{ "[\\]",     dwindle }, 
	{ "><>",      NULL },
};

/* Keybinds */
static const Key keys[] = {
	/* General */
	{ MODKEY,	                XK_Return, spawn,          SHCMD("st") },
	{ MODKEY,                       XK_d,      spawn,          SHCMD("rofi -show drun") },
	{ MODKEY,	                XK_q,      killclient,     {0} },
	{ MODKEY,	                XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },

	/* Layout */
	{ MODKEY,			XK_t,	   setlayout,	   {.v = &layouts[0]} },
	{ MODKEY,			XK_f,	   setlayout,	   {.v = &layouts[1]} },

	/* Focus */
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },

	/* Master Window */
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_p,      incnmaster,     {.i = -1 } },

	/* Monitors */
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	/* Temp */
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },

	/* Workspaces */
	TAGKEYS(XK_1, 0)
	TAGKEYS(XK_2, 1)
	TAGKEYS(XK_3, 2)
	TAGKEYS(XK_4, 3)
};

static const Button buttons[] = {
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};

