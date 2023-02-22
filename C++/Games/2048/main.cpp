#include <curses.h>
#include <cwchar>
#include <iostream>
#include <iomanip>
#include <ncurses.h>
#include <random>
#include <string>
#include <vector>
#include <stdlib.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	#include <ncurses/ncurses.h>
	#define clrscr "cls"
#else
	#include <ncurses.h>
	#define clrscr "clear"
#endif

class chessPlate {
public:
	int steps = 0;
	std::vector<std::vector<int>> mat;

private:
	std::random_device r;
	std::default_random_engine e;

public:
	explicit chessPlate() : mat(4, std::vector<int>(4, 0)), e(r()) {
		mat[get_random_coord(e)][get_random_coord(e)] = 2;
		mat[get_random_coord(e)][get_random_coord(e)] = 2;
	}
	
	inline bool move_up() {
		bool is_moved = false;
		for (int j = 0; j < 4; ++j) {
			for (int i = 1; i < 4; ++i) {
				if (mat[i][j] == 0) continue;
				bool is_combined = false;
				for (int k = i; k > 0; --k) {
					if (mat[k - 1][j] == 0) {
						mat[k - 1][j] = mat[k][j], mat[k][j] = 0;
						is_moved = true;
						continue;
					}
					if (mat[k - 1][j] != mat[k][j]) {
						break;
					}
					if (!is_combined) {
						is_combined = true;
						is_moved = true;
						mat[k - 1][j] *= 2, mat[k][j] = 0;
					}
				}
			}
		}
		return is_moved ? true : false;
	}

	inline bool move_down() {
		bool is_moved = false;
		for (int j = 0; j < 4; ++j) {
			for (int i = 2; i >= 0; --i) {
				if (mat[i][j] == 0) continue;
				bool is_combined = false;
				for (int k = i; k < 3; ++k) {
					if (mat[k + 1][j] == 0) {
						mat[k + 1][j] = mat[k][j], mat[k][j] = 0;
						is_moved = true;
						continue;
					}
					if (mat[k + 1][j] != mat[k][j]) {
						break;
					}
					if (!is_combined) {
						is_combined = true;
						is_moved = true;
						mat[k + 1][j] *= 2, mat[k][j] = 0;
					}
				}
			}
		}
		return is_moved ? true : false;
	}

	inline bool move_left() {
		bool is_moved = false;
		for (int i = 0; i < 4; ++i) {
			for (int j = 1; j < 4; ++j) {
				if (mat[i][j] == 0) continue;
				bool is_combined = false;
				for (int k = j; k > 0; --k) {
					if (mat[i][k - 1] == 0) {
						mat[i][k - 1] = mat[i][k], mat[i][k] = 0;
						is_moved = true;
						continue;
					}
					if (mat[i][k - 1] != mat[i][k]) {
						break;
					}
					if (!is_combined) {
						is_combined = true;
						is_moved = true;
						mat[i][k - 1] *= 2, mat[i][k] = 0;
					}
				}
			}
		}
		return is_moved ? true : false;
	}

	inline bool move_right() {
		bool is_moved = false;
		for (int i = 0; i < 4; ++i) {
			for (int j = 2; j >= 0; --j) {
				if (mat[i][j] == 0) continue;
				bool is_combined = false;
				for (int k = j; k < 3; ++k) {
					if (mat[i][k + 1] == 0) {
						mat[i][k + 1] = mat[i][k], mat[i][k] = 0;
						is_moved = true;
						continue;
					}
					if (mat[i][k + 1] != mat[i][k]) {
						break;
					}
					if (!is_combined) {
						is_combined = true;
						is_moved = true;
						mat[i][k + 1] *= 2, mat[i][k] = 0;
					}
				}
			}
		}
		return is_moved ? true : false;
	}

	inline void print_plate(WINDOW *window) {
		wrefresh(window);
		int y = 1, x = 10;
		int win_max_y = 0, win_may_x = 0;
		getmaxyx(window, win_max_y, win_may_x);
		mvwprintw(window, y++, win_may_x / 2 - 6, "%4d%s", steps, " step");
		mvwprintw(window, y++, x, "%s", "+------+------+------+------+");
		for (int i = 0; i < 4; ++i) {
			y = i * 2 + 3, x = 10;
			for (int j = 0; j < 4; ++j) {
				mvwprintw(window, y, x, "%s%5d%s", "|", mat[i][j], " ");
				x += 7;
			}
			mvwprintw(window, y++, x, "%s", "|");
			mvwprintw(window, y++, 10, "%s", "+------+------+------+------+");
		}
		mvwprintw(window, y++, 1, "%s", "k/KEY_UP: move up, KEY_DOWN: move down,");
		mvwprintw(window, y++, 1, "%s", "h/KEY_LEFT: move left, l/KEY_RIGHT: move right.");
		move(0, 0);
		refresh();
		wrefresh(window);
	}

	inline void next_step() {
		if (is_full()) return;
		int r = get_random_coord(e), c = get_random_coord(e);
		while(mat[r][c] != 0) {
			r = get_random_coord(e), c = get_random_coord(e);
		}
		mat[r][c] = 2;
		++steps;
	}

	bool is_full() {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (mat[i][j] == 0) return false;
				if (i < 3 && mat[i][j] == mat[i + 1][j]) return false;
				if (j < 3 && mat[i][j] == mat[i][j + 1]) return false;
			}
		}
		return true;
	}

	bool is_over() {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (mat[i][j] != mat[i][j + 1] || mat[i][j] != mat[i + 1][j]) {
					return false;
				}
			}
		}
		return true;
	}

private:
	int get_random_coord(std::default_random_engine &e) {
		std::uniform_int_distribution<int> uniform_dist(0, 3);
		return uniform_dist(e);
	}
};

class gameWindow {
public:
	int height = 18;
	int width = 50;
	int scr_max_y;
	int scr_max_x;

public:
	explicit gameWindow() {
		game_mat = new chessPlate;
	}

	inline void init_scr() {
		initscr();
		noecho();
		cbreak();
		getmaxyx(stdscr, scr_max_y, scr_max_x);
		game_win = newwin(height, width, scr_max_y / 2 - height / 2, scr_max_x / 2 - width / 2);
		keypad(game_win, true);
		box(game_win, 0, 0);
		refresh_all();
		game_mat->print_plate(game_win);
	}

	inline void listen_key() {
		while (true) {
			auto input_key = wgetch(game_win);
			if ((input_key == KEY_UP || input_key == 'k') && game_mat->move_up()) {
				game_mat->next_step();
				game_mat->print_plate(game_win);
				continue;
			}
			if ((input_key == KEY_DOWN || input_key == 'j') && game_mat->move_up()) {
				game_mat->next_step();
				game_mat->print_plate(game_win);
				continue;
			}
			if ((input_key == KEY_LEFT || input_key == 'h')&& game_mat->move_left()) {
				game_mat->next_step();
				game_mat->print_plate(game_win);
				continue;
			}
			if ((input_key == KEY_RIGHT || input_key == 'l') && game_mat->move_right()) {
				game_mat->next_step();
				game_mat->print_plate(game_win);
				continue;
			}
		}
	}

private:
	WINDOW *game_win;
	chessPlate *game_mat;

private:
	inline void refresh_all() {
		refresh();
		wrefresh(game_win);
	}
};

int main(int argc, char *argv[]) {
	auto game = new gameWindow;

	// TODO: make a game menu.

	// TODO: make a scoreboard.

	game->init_scr();
	game->listen_key();
	
	// while(true) {
	// 	auto input_key = wgetch(game_win);
	// 	if (input_key == KEY_UP) {
	// 		if (game_mat->move_up()) game_mat->next_step();
	// 		game_mat->print_plate(game_win);
	// 		continue;
	// 	}
	// }

	/* end ncurses */
	getch();
	endwin();
}
