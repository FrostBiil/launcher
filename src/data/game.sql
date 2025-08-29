CREATE TABLE game(
  id TEXT PRIMARY KEY,
  name TEXT NOT NULL,
  exec TEXT NOT NULL,
  args TEXT,
  workdir TEXT,
  icon TEXT,
  enabled INTEGER NOT NULL DEFAULT 1
);
