#include "include.h"
#include <curses.h>
#include <menu.h>

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

	inline bool is_full() {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (mat[i][j] == 0) return false;
				if (i < 3 && mat[i][j] == mat[i + 1][j]) return false;
				if (j < 3 && mat[i][j] == mat[i][j + 1]) return false;
			}
		}
		return true;
	}

	inline bool is_over() {
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
	inline int get_random_coord(std::default_random_engine &e) {
		std::uniform_int_distribution<int> uniform_dist(0, 3);
		return uniform_dist(e);
	}
};

class menuWindow {
public:
	inline explicit menuWindow() {
		choices = {
			"New game",
			"Continue",
			"Leaderboard",
			"Exit",
		};
		init_menu_window();
	}

	inline ~menuWindow() {
		close_menu();
	}

public:
	inline void print_menu() {
		mvprintw(LINES - 2, 0, "%s", "Press key Q to quit.");
		post_menu(main_menu);
		refresh();
		listen_key();
	}

private:
	inline void init_menu_window() {
		getmaxyx(menu_win, scr_max_y, scr_max_x);
		// ITEM *curr_item = nullptr;
		int n_choices = choices.size();
		my_items = (ITEM **)calloc(n_choices + 1, sizeof (ITEM *));
		for (int i = 0; i < n_choices; ++i) {
			my_items[i] = new_item(choices[i].c_str(), choices[i].c_str());
		}
		my_items[n_choices] = nullptr;
		main_menu = new_menu((ITEM **) my_items);
	}

	inline void close_menu() {
		free_item(my_items[0]);
		free_item(my_items[1]);
		free_menu(main_menu);
	}

	inline void listen_key() {
		int c = 0;
		while ((c = getch()) != 'q') {
			switch (c) {
				case KEY_DOWN:
					menu_driver(main_menu, REQ_DOWN_ITEM);
					break;
				case KEY_UP:
					menu_driver(main_menu, REQ_UP_ITEM);
					break;
				default:
					break;
			}
		}
	} 

private:
	int witdth = 40;
	int height = 20;
	int scr_max_y = 0;
	int scr_max_x = 0;
	std::vector<std::string> choices;
	WINDOW *menu_win = nullptr;
	ITEM **my_items = nullptr;
	MENU *main_menu = nullptr;
};

class gameWindow {
public:
	explicit gameWindow() {
		game_mat = new chessPlate;
	}

	inline void init_game_window() {
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
			if ((input_key == KEY_DOWN || input_key == 'j') && game_mat->move_down()) {
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
	int height = 18;
	int width = 50;
	int scr_max_y;
	int scr_max_x;
	WINDOW *game_win;
	chessPlate *game_mat;

private:
	inline void refresh_all() {
		refresh();
		wrefresh(game_win);
	}
};

inline void init_scr() {
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, true);
}

inline void end_scr() {
	getch();
	endwin();
}

int main(int argc, char *argv[]) {
	init_scr();
	auto menu = new menuWindow;
	auto game = new gameWindow;
	
	// TODO: make a game menu.
	
	// TODO: make a scoreboard.
	menu->print_menu();
	// game->init_game_window();
	// game->listen_key();	
	
	// while(true) {
	// 	auto input_key = wgetch(game_win);
	// 	if (input_key == KEY_UP) {
	// 		if (game_mat->move_up()) game_mat->next_step();
	// 		game_mat->print_plate(game_win);
	// 		continue;
	// 	}
	// }

	/* end ncurses */
	end_scr();
}
