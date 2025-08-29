#pragma once

#include <sqlite3.h>

enum ERR {OK, ERROR};

sqlite3 *setupDB();
