#include <glib.h>
#include "../src/app/catalog.h"

static void test_catalog_count(void) {
  size_t count;
  const Game *games = catalog_get_all(&count);
  g_assert_cmpuint(count, ==, 2);
  g_assert_cmpstr(games[0].name, ==, "Example Game 1");
}

int main(int argc, char **argv) {
  g_test_init(&argc, &argv, NULL);
  g_test_add_func("/catalog/count", test_catalog_count);
  return g_test_run();
}
