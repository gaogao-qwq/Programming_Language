#include <cwchar>
#include <iostream>
#include <iomanip>
#include <random>
#include <string>
#include <vector>
#include <stdlib.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	// For some reasons the ncurses build on Windows will be stored
	// in /ncurses directory.
	#include <ncurses/ncurses.h>
	#include <ncurses/curses.h>
	#include <ncurses/menu.h>
	#define clrscr "cls"
#else
	#include <ncurses.h>
	#include <curses.h>
	#include <menu.h>
	#define clrscr "clear"
#endif

#define CTRLD 4;
