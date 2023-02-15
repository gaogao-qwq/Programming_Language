#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <stdlib.h>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
	#include <Windows.h>
	#define KEYDOWN [](int vk_code){ return GetAsyncKeyState(vk_code) < 0; }
	#define clrscr "cls"
#else
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
		mat[get_random_int(e)][get_random_int(e)] = 2;
		mat[get_random_int(e)][get_random_int(e)] = 2;
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

	inline void print_plate() {
		system(clrscr);
		std::cout << std::setw(16) << steps << std::endl;
		std::cout << "+------+------+------+------+" << std::endl;
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				std::cout << "|";
				std::cout << std::setw(5) << mat[i][j] << " ";
			}
			std::cout << "|" << std::endl << "+------+------+------+------+" << std::endl;
		}
	}

	inline void next_step() {
		if (full()) return;
		int r = get_random_int(e), c = get_random_int(e);
		while(mat[r][c] != 0) {
			r = get_random_int(e), c = get_random_int(e);
		}
		mat[r][c] = 2;
		++steps;
		print_plate();
	}

private:
	bool full() {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (mat[i][j] == 0) return false;
				if (i < 3 && mat[i][j] == mat[i + 1][j]) return false;
				if (j < 3 && mat[i][j] == mat[i][j + 1]) return false;
			}
		}
		return true;
	}

	int get_random_int(std::default_random_engine &e) {
		std::uniform_int_distribution<int> uniform_dist(0, 3);
		return uniform_dist(e);
	}
};

int main(int argc, char *argv[]) {
	auto game = new chessPlate();
	game->print_plate();
	while(true) {
		if (KEYDOWN(VK_UP) || KEYDOWN('J')) {
			if (game->move_up()) game->next_step();
			std::cin.sync();
			Sleep(100);
			continue;
		}
		if (KEYDOWN(VK_DOWN) || KEYDOWN('K')) {
			if (game->move_down()) game->next_step();
			std::cin.sync();
			Sleep(100);
			continue;
		}
		if (KEYDOWN(VK_LEFT) || KEYDOWN('H')) {
			if (game->move_left()) game->next_step();
			std::cin.sync();
			Sleep(100);
			continue;
		}
		if (KEYDOWN(VK_RIGHT) || KEYDOWN('L')) {
			if (game->move_right()) game->next_step();
			std::cin.sync();
			Sleep(100);
			continue;
		}
	}
}