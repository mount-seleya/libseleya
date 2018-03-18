#include <stdio.h>

#include "seleya/seleya.h"
#include "seleya/monitor.h"
#include "seleya/window.h"

int main(int argc, char *argv[])
{
  seleya_monitor_t *m, *n;
  seleya_monitor_mode_t *vm;
  seleya_window_t *w;
  m = seleya_init();

  n = m;
  while(n)
  {
    fprintf(stdout, "monitor (%s) - %i\n", n->name, n->primary);
    vm = n->modes;
    while(vm)
    {
      fprintf(stdout, " %ix%i@%i - %i\n", vm->w, vm->h, vm->refresh_rate, vm->current);
      vm = vm->next;
    }
    n = n->next;
  }

  w = seleya_window_create(600, 400, "seleya 3d engine", NULL);
  seleya_loop(w);
  seleya_window_destroy(w);
  seleya_terminate(m);

  return 0;
}
