#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char buff[256];
  int error;
  lua_State *L = luaL_newstate(); /* opens lua */
  luaL_openlibs(L);               /* opens all standard libraries */

  while (fgets(buff, sizeof(buff), stdin) != NULL) {
    error = luaL_loadbuffer(L, buff, strlen(buff), buff);
    lua_pcall(L, 0, 0, 0);
    if (error) {
      fprintf(stderr, "%s", lua_tostring(L, -1));
      lua_pop(L, 1); /* pop error message */
    }
  }
  lua_close(L);
  return 0;
}
