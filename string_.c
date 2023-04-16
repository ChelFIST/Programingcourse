#include "string_.h"

// возвращает количество символов строки
int strLen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;

    return end - begin;
}

void test_strLen_() {
    char s1[] = "Hello";
    assert(strLen_(s1) == 5);

    char s2[] = "";
    assert(strLen_(s2) == 0);

    char s3[] = "\tHello\t";
    assert(strLen_(s3) == 7);
}

int strcmp_(const char *s1, const char *s2) {
    while (*s1 && *s1 == *s2) {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

// возвращает указатель на первый элемент с кодом ch, расположенным на ленте памяти между
// адресами begin и end, не включая end. Если символ не найден, возвращается значение end
char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

void test_find() {
    char s1[] = "Hello";
    char *s11 = find(s1, s1 + 3, 101);
    char *s12 = "ello";
    assert(strcmp_(s11, s12) == 0);

    char s2[] = "Hello";
    char *s21 = find(s2, s2 + 4, 107);
    char *s22 = "o";
    assert(strcmp_(s21, s22) == 0);
}

// возвращает указатель на первый символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.
// Если символ не найден, возвращается адрес первого ноль-символа
char *findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin))
        begin++;

    return begin;
}

void test_findNonSpace() {
    char s1[] = "Hello";
    char *s11 = findNonSpace(s1);
    char *s12 = "Hello";
    assert(strcmp_(s11, s12) == 0);

    char s2[] = "  Hel\tlo";
    char *s21 = findNonSpace(s2);
    char *s22 = "Hel\tlo";
    assert(strcmp_(s21, s22) == 0);

    char s3[] = "\t  ";
    char *s31 = findNonSpace(s3);
    char *s32 = "";
    assert(strcmp_(s31, s32) == 0);
}

// возвращает указатель на первый пробельный символ, расположенный на ленте памяти,
// начиная с адреса begin или на первый ноль-символ
char *findSpace(char *begin) {
    while (*begin != '\0' && !isspace(*begin))
        begin++;

    return begin;
}

void test_findSpace() {
    char s1[] = "Hello";
    char *s11 = findSpace(s1);
    char *s12 = "";
    assert(strcmp_(s11, s12) == 0);

    char s2[] = "  Hel\tlo";
    char *s21 = findSpace(s2);
    char *s22 = "  Hel\tlo";
    assert(strcmp_(s21, s22) == 0);

    char s3[] = "l\t  j";
    char *s31 = findSpace(s3);
    char *s32 = "\t  j";
    assert(strcmp_(s31, s32) == 0);
}

// возвращает указатель на первый символ справа , отличный от пробельных,
// расположенный на ленте памяти, начиная с rbegin (последний символ строки,
// за которым следует ноль-символ) и заканчивая rend (адрес символа перед началом строки).
// Если символ не найден, возвращается адрес rend
char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && isspace(*rbegin))
        rbegin--;

    return (rbegin != rend) ? rbegin : rbegin + 1;
}

void test_findNonSpaceReverse() {
    char s1[] = "Hello  ";
    char *s11 = findNonSpaceReverse(s1 + 6, s1 - 1);
    char *s12 = "o  ";
    assert(strcmp_(s11, s12) == 0);

    char s2[] = "  Hel lo";
    char *s21 = findNonSpaceReverse(s2 + 7, s2 - 1);
    char *s22 = "o";
    assert(strcmp_(s21, s22) == 0);

    char s3[] = "    ";
    char *s31 = findNonSpaceReverse(s3 + 3, s3 - 1);
    char *s32 = "    ";
    assert(strcmp_(s31, s32) == 0);
}

// возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти,
// начиная с rbegin и заканчивая rend. Если символ не найден, возвращается адрес rend.
char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && !isspace(*rbegin))
        rbegin--;

    return (rbegin != rend) ? rbegin : rbegin + 1;
}

void test_findSpaceReverse() {
    char s1[] = "Hello  ";
    char *s11 = findSpaceReverse(s1 + 6, s1 - 1);
    char *s12 = " ";
    assert(strcmp_(s11, s12) == 0);

    char s2[] = "  Hel lo";
    char *s21 = findSpaceReverse(s2 + 7, s2 - 1);
    char *s22 = " lo";
    assert(strcmp_(s21, s22) == 0);

    char s3[] = "Hello";
    char *s31 = findSpaceReverse(s3 + 4, s3 - 1);
    char *s32 = "Hello";
    assert(strcmp_(s31, s32) == 0);
}

// записывает по адресу beginDestination фрагмент памяти, начиная с адреса beginSource
// до endSource. Возвращает указатель на следующий свободный фрагмент памяти
// в beginDestination
char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    int size = endSource - beginSource;
    memcpy(beginDestination, beginSource, size);

    return beginDestination + size;
}

void test_copy() {
    char s1[] = "wo";
    char s11[] = "r l d";
    char *s12 = copy(s11, s11 + 5, s1 + 2);
    assert(s1 + 7 == s12);

    char s2[] = "";
    char s21[] = "gh;9";
    char *s22 = copy(s21, s21 + 4, s2);
    assert(s2 + 4 == s22);

    char s3[] = "1t";
    char s31[] = "8hi ;qw4";
    char *s32 = copy(s31 + 1, s31 + 6, s3 + 2);
    assert(s3 + 7 == s32);
}

bool isAlpha(char a) {
    return isalpha(a);
}

// записывает по адресу beginDestination элементы из фрагмента памяти,
// начиная с beginSource, заканчивая endSource, удовлетворяющие функции-предикату f.
// Функция возвращает указатель на следующий свободный для записи фрагмент в памяти
char *copyIf(char *beginSource, const char *endSource, char *beginDestination,
             bool (*f)(char)) {
    while (beginSource < endSource) {
        if (f(*beginSource)) {
            memcpy(beginDestination, beginSource, 1);
            beginDestination++;
        }
        beginSource++;
    }

    return beginDestination;
}

void test_copyIf() {
    char s1[] = "wo";
    char s11[] = "r l d";
    char *s12 = copyIf(s11, s11 + 5, s1 + 2, isAlpha);
    assert(s1 + 5 == s12);

    char s2[] = "123";
    char s21[] = "6750";
    char *s22 = copyIf(s21, s21 + 4, s2 + 3, isAlpha);
    assert(s2 + 3 == s22);

    char s3[] = "1t";
    char s31[] = "8hi ;qw4";
    char *s32 = copyIf(s31 + 1, s31 + 6, s3 + 2, isAlpha);
    assert(s3 + 5 == s32);
}

// записывает по адресу beginDestination элементы из фрагмента памяти,
// начиная с rbeginSource заканчивая rendSource, удовлетворяющие функции-предикату f.
// Функция возвращает значение beginDestination по окончанию работы функции.
char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination,
                    bool (*f)(char)) {
    while (rbeginSource > rendSource) {
        if (f(*rbeginSource)) {
            memcpy(beginDestination, rbeginSource, 1);
            beginDestination++;
        }
        rbeginSource--;
    }

    return beginDestination;
}

void test_copyIfReverse() {
    char s1[] = "";
    char s11[] = "pdl92r;;ow";
    char *s12 = copyIfReverse(s11 + 9, s11, s1, isAlpha);
    assert(s1 + 5 == s12);

    char s2[] = "123";
    char s21[] = "6750";
    char *s22 = copyIfReverse(s21 + 3, s21, s2 + 3, isAlpha);
    assert(s2 + 3 == s22);

    char s3[] = "1t";
    char s31[] = "8hi ;qw4";
    char *s32 = copyIfReverse(s31 + 6, s31 + 2, s3 + 2, isAlpha);
    assert(s3 + 4 == s32);
}


typedef struct WordDescriptor {
    char *begin;
    char *end;
} WordDescriptor;

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}

void getBagOfWords(BagOfWords *bag, char *s) {
    WordDescriptor word;
    char *beginSearch = s;
    while (getWord(beginSearch, &word)) {
        bag->words[bag->size].begin = word.begin;
        bag->words[bag->size].end = word.end;
        bag->size++;
        beginSearch = word.end;
    }
}

bool hasEqualWords(char *s) {
    getBagOfWords(&_bag, s);
    for (int i = 0; i < _bag.size; i++)
        for (int j = i + 1; j < _bag.size; j++)
            if (areWordsEqual(_bag.words[i], _bag.words[j]) == 0)
                return true;
    return false;
}







