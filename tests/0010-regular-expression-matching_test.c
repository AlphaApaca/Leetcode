#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void test_regular_expression_matching() {
    //Testcase 1
    char* s = "aa";
    char* p = "a";
    bool expected = false;
    bool actual = isMatch(s, p);
    printf("Testcase 1: %s\n", (actual == expected)? "Passed" : "Failed");

    //Testcase 2
    s = "aa";
    p = "a*";
    expected = true;
    actual = isMatch(s, p);
    printf("Testcase 2: %s\n", (actual == expected)? "Passed" : "Failed");

    //Testcase 3
    s = "ab";
    p = ".*";
    expected = true;
    actual = isMatch(s, p);
    printf("Testcase 3: %s\n", (actual == expected)? "Passed" : "Failed");

    //Testcase 4
    s = "aab";
    p = "c*a*b";
    expected = true;
    actual = isMatch(s, p);
    printf("Testcase 4: %s\n", (actual == expected)? "Passed" : "Failed");

    //Testcase 5
    s = "mississippi";
    p = "mis*is*p*.";
    expected = false;
    actual = isMatch(s, p);
    printf("Testcase 5: %s\n", (actual == expected)? "Passed" : "Failed");

    //Testcase 6
    s = "ab";
    p = ".*c";
    expected = false;
    actual = isMatch(s, p);
    printf("Testcase 6: %s\n", (actual == expected)? "Passed" : "Failed");

    //Testcase 7
    s = "aaa";
    p = "ab*a*c*a";
    expected = true;
    actual = isMatch(s, p);
    printf("Testcase 7: %s\n", (actual == expected)? "Passed" : "Failed");

    //Testcase 8
    s = "aaa";
    p = "ab*a*c*a*b";
    expected = false;
    actual = isMatch(s, p);
    printf("Testcase 8: %s\n", (actual == expected)? "Passed" : "Failed");
    //Testcase 9
    s = "aaa";
    p = "ab*a*c*a*b*";
    expected = true;
    actual = isMatch(s, p);
    printf("Testcase 9: %s\n", (actual == expected)? "Passed" : "Failed");
    //Testcase 10
    s = "aaa";
    p = "ab*a*c*a*b*";
    expected = true;
    actual = isMatch(s, p);
    printf("Testcase 10: %s\n", (actual == expected)? "Passed" : "Failed");

}

int main() {
    test_regular_expression_matching();
    return 0;
}