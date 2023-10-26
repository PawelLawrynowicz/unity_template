#include <stdio.h>
#include <unity.h>

void setUp(void) {
}
void tearDown(void) {
}

void testAdding(void) {
  TEST_ASSERT_EQUAL_INT32(5, 3 + 2);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(testAdding);

  return UNITY_END();
}