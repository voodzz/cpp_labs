#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include "containersLib.h"

int main() {
    std::multiset<std::string> A;
    A = readMultiset("CMakeFiles/data/inputSet1.txt");
    std::multiset<std::string> B;
    B = readMultiset("CMakeFiles/data/inputSet2.txt");

    std::multiset<std::string> combination;
    std::set_union(A.cbegin(), A.cend(), B.cbegin(), B.cend(),
                   std::inserter(combination, combination.cbegin()));
    printMultiset("CMakeFiles/data/outputUnion.txt", combination);

    std::multiset<std::string> intersection;
    std::set_intersection(A.cbegin(), A.cend(), B.cbegin(), B.cend(),
                          std::inserter(intersection, intersection.cbegin()));
    printMultiset("CMakeFiles/data/outputIntersection.txt", intersection);

    std::multiset<std::string> differenceAMinusB;
    std::set_difference(A.cbegin(), A.cend(), B.cbegin(), B.cend(),
                        std::inserter(differenceAMinusB, differenceAMinusB.cbegin()));
    printMultiset("CMakeFiles/data/outputDifferenceAB.txt", differenceAMinusB);

    std::multiset<std::string> differenceBMinusA;
    std::set_difference(B.cbegin(), B.cend(), A.cbegin(), A.cend(),
                        std::inserter(differenceBMinusA, differenceBMinusA.cbegin()));
    printMultiset("CMakeFiles/data/outputDifferenceBA.txt", differenceBMinusA);
    return 0;
}