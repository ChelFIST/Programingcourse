#include <stdbool.h>
#include <ctype.h>
#include <assert.h>
#include <memory.h>

int strLen_(const char *begin);

void test_strLen_();

int strcmp_(const char *s1, const char *s2);

char *find(char *begin, char *end, int ch);

void test_find();

char *findNonSpace(char *begin);

void test_findNonSpace();

char *findSpace(char *begin);

void test_findSpace();

char *findNonSpaceReverse(char *rbegin, const char *rend);

void test_findNonSpaceReverse();

char *findSpaceReverse(char *rbegin, const char *rend);

void test_findSpaceReverse();

char *copy(const char *beginSource, const char *endSource, char *beginDestination);

void test_copy();

char *copyIf(char *beginSource, const char *endSource, char *beginDestination,
             bool (*f)(char));

void test_copyIf();

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination,
                    bool (*f)(char));

void test_copyIfReverse();

