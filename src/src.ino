#define __V3__

void myloop();
void mysetup();

#ifdef __V1__
#include "v_1_seguidor.h"
#endif

#ifdef __V2__
#include "v_2_seguidor.h"
#endif 

#ifdef __V3__
#include "v_3_seguidor.h"
#endif 

#ifdef __TEST_S__
#include "test_sensores.h"
#endif 

void setup() {
  mysetup();
}

void loop() {
  myloop();
}
