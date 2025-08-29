#pragma once
#include <sqlite3.h>
#include "../models/game.h"

void game_upsert(sqlite3 *db, const Game *g);
