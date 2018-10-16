#include "./alglib/ap.h"
#include "./alglib/specialfunctions.h"

int main(int argc, char *argv[])
{
  alglib_impl::ae_int_t n = 0;
  double expValue = 0.601811267;
  std::cout << alglib_impl::poissondistribution(n, expValue, NULL);
  return 0;
}