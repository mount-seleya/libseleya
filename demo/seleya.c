#include "seleya/seleya.h"
#include "seleya/monitor.h"

int main(int argc, char *argv[])
{
  seleya_init();
  seleya_create_window(400, 200, "hello world");
  return 0;
}
