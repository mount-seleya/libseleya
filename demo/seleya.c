#include <stdio.h>

#include "seleya/seleya.h"
#include "seleya/monitor.h"

int main(int argc, char *argv[])
{
  seleya_monitor_t *m, *n;
  seleya_monitor_mode_t *vm;
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

  return 0;
}
