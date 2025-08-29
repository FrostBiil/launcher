CREATE TABLE news(
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  game_id TEXT, --nullable for generel news
  title TEXT NOT NULL,
  body TEXT NOT NULL,
  create_at INTEGER NOT NULL,
  FOREIGN KEY(game_id) REFERENCES game(id) ON DELETE CASCADE
);
