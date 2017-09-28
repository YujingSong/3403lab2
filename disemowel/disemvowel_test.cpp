#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  char* jj;
  jj = disemvowel((char*) "");
  ASSERT_STREQ("", jj);
  free(jj);
}

TEST(Disemvowel, HandleNoVowels) {
  char* jj;
  jj = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", jj);
  free(jj);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char* jj;
  jj = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", jj);
  free(jj);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char* jj;
  jj = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", jj);
  free(jj);
}

TEST(Disemvowel, HandlePunctuation) {
  char* jj;
  jj = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", jj);
  free(jj);
}

TEST(Disemvowel, HandleLongString) {
  char* str;
  int size;
  int i;
  char* jj;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  jj = disemvowel(str);
  
  ASSERT_STREQ("xyz", jj);
  
  free(jj);

  free(str);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
