#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char buff[256];
  int error;
  lua_State *L = lua_open(); /* opens lua */
  luaopen_base(L);           /* opens the basic library  */
  luaopen_table(L);          /* opens the table library */
  luaopen_io(L);             /* opens the I/O Library */
  luaopen_string(L);         /* opens the string lib */
  luaopen_math(L);           /* opens the math lib */

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
