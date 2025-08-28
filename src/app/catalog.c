#include "catalog.h"

// Temporary hardcoded games (MVP) fetch from db later
static const Game GAME_LIST[] = {
    {
        .id = "example_game_1",
        .name = "Example Game 1",
        .exec = "C:/Games/ExampleGame1/examplegame1.exe",
        .args = "",
        .workdir = "C:/Games/ExampleGame1",
        .enabled = true
    },
    {
        .id = "example_game_2",
        .name = "Example Game 2",
        .exec = "C:/Games/ExampleGame2/examplegame2.exe",
        .args = "",
        .workdir = "C:/Games/ExampleGame2",
        .enabled = true
    }
};

const Game* catalog_get_all(size_t *count) {
    if (count) *count = sizeof(GAME_LIST) / sizeof(GAME_LIST[0]);
    return GAME_LIST;
}
