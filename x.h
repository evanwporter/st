#ifndef ST_X_H
#define ST_X_H

#include <X11/Xlib.h>
#include <X11/Xft/Xft.h>

/* Defined by libnotify/notify.h. */
#undef MAX
#undef MIN

extern char *argv0;
#include "st.h"

/* types used in config.h */
typedef struct {
	uint mod;
	KeySym keysym;
	void (*func)(const Arg *);
	const Arg arg;
} Shortcut;

typedef struct {
	uint mod;
	uint button;
	void (*func)(const Arg *);
	const Arg arg;
	uint  release;
} MouseShortcut;

typedef struct {
	KeySym k;
	uint mask;
	char *s;
	/* three-valued logic variables: 0 indifferent, 1 on, -1 off */
	signed char appkey;    /* application keypad */
	signed char appcursor; /* application cursor */
} Key;

/* Undercurl slope types */
enum undercurl_slope_type {
	UNDERCURL_SLOPE_ASCENDING = 0,
	UNDERCURL_SLOPE_TOP_CAP = 1,
	UNDERCURL_SLOPE_DESCENDING = 2,
	UNDERCURL_SLOPE_BOTTOM_CAP = 3
};

 /* X modifiers */
#define XK_ANY_MOD    UINT_MAX
#define XK_NO_MOD     0
#define XK_SWITCH_MOD (1<<13|1<<14)

/* function definitions used in config.h */
void clipcopy(const Arg *);
void clippaste(const Arg *);
void numlock(const Arg *);
void selpaste(const Arg *);
void zoom(const Arg *);
void zoomabs(const Arg *);
void zoomreset(const Arg *);
void ttysend(const Arg *);

#endif // ST_X_H
