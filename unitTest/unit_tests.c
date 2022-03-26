#include "unity.h"
#include "../include/adjList.h"
#include "../include/interface.h"

static void testReadFile(){
  // a benign input file and output file
  const FILE *fp1 = fopen("Final_Map.map","r");
  const FILE *fp2 = fopen("original.dat","w");
  TEST_ASSERT_NOT_NULL(fp1);
  TEST_ASSERT_NOT_NULL(fp2);
}

static void testCheckNumberString(){
  TEST_ASSERT_EQUAL_INT(0,checkNumberString("1024"));
  TEST_ASSERT_EQUAL_INT(-1,checkNumberString("asdf"));
}

static void testFindNodeById(){
  // a long int which is in the set of vertex ids
  TEST_ASSERT_EQUAL_INT(0,findNodeById(-8847));
  // a long int which is not in the set of vertex ids
  TEST_ASSERT_EQUAL_INT(-1,findNodeById(1000));
}

static void testCheckAnswer(){
  TEST_ASSERT_EQUAL_INT(-1,checkAnswer("asdf"));
  TEST_ASSERT_EQUAL_INT(-1,checkAnswer("1000"));
  TEST_ASSERT_EQUAL_INT(-1,checkAnswer("-1867901283"));
  TEST_ASSERT_EQUAL_INT(344,checkAnswer("-8761"));
}

static void testDijkstra(){
  TEST_ASSERT_EQUAL_INT(-1,dijkstra(1,1));
  // two points that can be reached
  TEST_ASSERT_EQUAL_INT(0,dijkstra(163,344));
  const FILE *fp = fopen("shortest.dat","w");
  TEST_ASSERT_NOT_NULL(fp);
}

void setUp(){

}
void tearDown(){

}

int main() {
  UNITY_BEGIN();
  readFile();
  RUN_TEST(testReadFile);
  RUN_TEST(testCheckNumberString);
  RUN_TEST(testFindNodeById);
  RUN_TEST(testCheckAnswer);
  RUN_TEST(testDijkstra);

  return UNITY_END();
}
