//this program compares two words to see if they are anamgrams. 

#include <stdio.h>
#define N 26

int main()
{

    char ch;
    int i, count[N] = {0};
    int count_zeros = 0;

    printf("Enter a word: ");
    while ((ch = getchar()) != '\n')
        count[ch-'a']++;

    printf("Enter the second word: ");
    while ((ch = getchar()) != '\n')
        count[ch-'a']--;

    for(i=0; i<N; i++)
        if(count[i] == 0)
            count_zeros++;
    

    if (count_zeros == N)
        printf("The words are anagrams.");
    else
        printf("The words are NOT anagrams.:");

    return 0;
}