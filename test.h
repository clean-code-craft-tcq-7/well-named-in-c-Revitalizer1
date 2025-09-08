#ifndef TEST_H
#define TEST_H

void testNumberToPair(int pairNumber, enum MajorColor expectedMajor, enum MinorColor expectedMinor);
void testPairToNumber(enum MajorColor major, enum MinorColor minor, int expectedPairNumber);
void runAllTests();

#endif /* TEST_H */