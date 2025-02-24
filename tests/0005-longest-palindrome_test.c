//0005-longest-palindrome_test.c
#include <stdio.h>
#include <stdlib.h>
#include "../src/0005-longest-palindrome.c"

void test_longest_palindrome() {
    // testcase 1
    char* s1 = "babad";
    char* answer1 = "bab";
    char* result1 = longestPalindrome(s1);
    printf("%s\n", result1);
    if (strcmp(result1, answer1) == 0) {
        printf("Testcase 1 passed. result: %s, answer: %s\n", result1, answer1);
    }
    else {
        printf("Testcase 1 failed. result: %s, answer: %s\n", result1, answer1);
    }

    //testcase 2
    char* s2 = "cbbd";
    char* answer2 = "bb";
    char* result2 = longestPalindrome(s2);
    printf("%s\n", result2);
    if (strcmp(result2, answer2) == 0) {
        printf("Testcase 2 passed. result: %s, answer: %s\n", result2, answer2);
    }
    else {
        printf("Testcase 2 failed. result: %s, answer: %s\n", result2, answer2);
    }
    
    //testcase 3
    char* s3 = "a";
    char* answer3 = "a";
    char* result3 = longestPalindrome(s3);
    printf("%s\n", result3);
    if (strcmp(result3, answer3) == 0) {
        printf("Testcase 3 passed. result: %s, answer: %s\n", result3, answer3);
    }
    else {
        printf("Testcase 3 failed. result: %s, answer: %s\n", result3, answer3);
    }

    //testcase 4
    char* s4 = "ac";
    char* answer4 = "a";
    char* result4 = longestPalindrome(s4);
    printf("%s\n", result4);
    if (strcmp(result4, answer4) == 0) {
        printf("Testcase 4 passed. result: %s, answer: %s\n", result4, answer4);
    }
    else {
        printf("Testcase 4 failed. result: %s, answer: %s\n", result4, answer4);
    }

    //testcase 5 对，就是这个爆内存了
    char* s5 = "kyyrjtdplseovzwjkykrjwhxquwxsfsorjiumvxjhjmgeueafubtonhlerrgsgohfosqssmizcuqryqomsipovhhodpfyudtusjhonlqabhxfahfcjqxyckycstcqwxvicwkjeuboerkmjshfgiglceycmycadpnvoeaurqatesivajoqdilynbcihnidbizwkuaoegmytopzdmvvoewvhebqzskseeubnretjgnmyjwwgcooytfojeuzcuyhsznbcaiqpwcyusyyywqmmvqzvvceylnuwcbxybhqpvjumzomnabrjgcfaabqmiotlfojnyuolostmtacbwmwlqdfkbfikusuqtupdwdrjwqmuudbcvtpieiwteqbeyfyqejglmxofdjksqmzeugwvuniaxdrunyunnqpbnfbgqemvamaxuhjbyzqmhalrprhnindrkbopwbwsjeqrmyqipnqvjqzpjalqyfvaavyhytetllzupxjwozdfpmjhjlrnitnjgapzrakcqahaqetwllaaiadalmxgvpawqpgecojxfvcgxsbrldktufdrogkogbltcezflyctklpqrjymqzyzmtlssnavzcquytcskcnjzzrytsvawkavzboncxlhqfiofuohehaygxidxsofhmhzygklliovnwqbwwiiyarxtoihvjkdrzqsnmhdtdlpckuayhtfyirnhkrhbrwkdymjrjklonyggqnxhfvtkqxoicakzsxmgczpwhpkzcntkcwhkdkxvfnjbvjjoumczjyvdgkfukfuldolqnauvoyhoheoqvpwoisniv";
    char* answer5 = "qahaq";
    char* result5 = longestPalindrome(s5);
    printf("%s\n", result5);
    if (strcmp(result5, answer5) == 0) {
        printf("Testcase 5 passed. result: %s, answer: %s\n", result5, answer5);
    }
    else {
        printf("Testcase 5 failed. result: %s, answer: %s\n", result5, answer5);
    }
}

int main() {
    // printf("%d\n", (5 % 2));
    test_longest_palindrome();
    return 0;
}