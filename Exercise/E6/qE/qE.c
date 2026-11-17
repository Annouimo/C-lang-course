#include <stddef.h>
#include <stdio.h>
#include <string.h>

enum {
    CHESS_BOARD_LIMIT = 25,
};
enum ChessBoard {
    Empty,
    HorseControl,
    Fence,
};
enum MoveMode {
    Down,
    Right,
};
struct Position {
    int x;
    int y;
};

static enum ChessBoard _chess_board_data[CHESS_BOARD_LIMIT][CHESS_BOARD_LIMIT] = {};
enum ChessBoard get_chess_board(int x, int y);
void set_chess_board(int x, int y, enum ChessBoard value);

void set_fence_in_chess_board(struct Position start, struct Position end);
void set_horse_control_in_chess_board(struct Position horse);

struct Position get_former_position(
    struct Position this_position,
    enum MoveMode move_mode
);
size_t find_path_count(struct Position start, struct Position end);

static size_t chess_board_path_cache[CHESS_BOARD_LIMIT][CHESS_BOARD_LIMIT] = {};
void chess_board_cache_write(struct Position position, size_t value);
void chess_board_cache_init();

int main(void){
    struct Position start = {0,0}, end, horse;
    scanf("%d%d%d%d", &end.x, &end.y, &horse.x, &horse.y);
    set_fence_in_chess_board(start, end);
    set_horse_control_in_chess_board(horse);

    chess_board_cache_init();
    printf("%zu", find_path_count(start, end));
    return 0;
}

enum ChessBoard get_chess_board(int x, int y){
    if (x<0 || y<0) {
        return Fence;
    }
    else {
        return _chess_board_data[x][y];
    }
}
void set_chess_board(int x, int y, enum ChessBoard value){
    if (x<0 || y<0) {
        return;
    }
    else {
        _chess_board_data[x][y] = value;
    }
}

void set_fence_in_chess_board(struct Position start, struct Position end){
    for (size_t i = start.x; i < end.x; i++) {
        set_chess_board(i, start.y - 1, Fence);
        set_chess_board(i, end.y + 1, Fence);
    }
    for (size_t i = start.y; i < end.y; i++) {
        set_chess_board(start.x - 1, i, Fence);
        set_chess_board(end.x + 1, i, Fence);
    }
}
void set_horse_control_in_chess_board(struct Position horse){
    static const struct Position horse_control[9] = {
        {1,2}, {1,-2}, {2,1}, {2,-1},
        {-1,2}, {-1,-2}, {-2,1}, {-2,-1}, {0,0},
    };
    for (size_t i = 0; i < 9; i++) {
        set_chess_board(
            horse.x + horse_control[i].x,
            horse.y + horse_control[i].y,
            HorseControl
        );
    }
}

size_t find_path_count(struct Position start, struct Position end){
    if (start.x == end.x && start.y == end.y) {
        return 1;
    }
    if (get_chess_board(end.x, end.y) != Empty) {
        return 0;
    }
    size_t cache = chess_board_path_cache[end.x][end.y];
    if (cache != (size_t)(-1)) {
        return cache;
    }
    size_t result =
        find_path_count(start, get_former_position(end, Right))+
        find_path_count(start, get_former_position(end, Down));
    chess_board_cache_write(end, result);
    return result;
}

struct Position get_former_position(
    struct Position this_position,
    enum MoveMode move_mode
){
    struct Position former_position = this_position;
    switch (move_mode) {
        case Down:
            former_position.y--;
            return former_position;
        case Right:
            former_position.x--;
            return former_position;
    }
}

void chess_board_cache_init(){
    memset(chess_board_path_cache, 0xFF, sizeof(chess_board_path_cache));
}

void chess_board_cache_write(struct Position position, size_t value){
    chess_board_path_cache[position.x][position.y] = value;
}
