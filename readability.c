#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{

    string text = get_string("Text: ");

    float letters = 0, words = 1, sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //counts number of letters
        if (isalpha(text[i]))
        {
            letters++;
        }
        //counts number of words
        if (isspace(text[i]))
        {
            words++;
        }
        //counts number of sentences
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    //calculates the average number of letters per 100 words
    float l = letters / words * 100;
    //calculates the average number of sentences per 100 words
    float s = sentences / words * 100;
    
    float index = 0.0588 * l - 0.296 * s - 15.8;
    int indexi = round(index);
    //determines readability index
    if (indexi >= 1 && indexi <= 16)
    {
        printf("Grade %i\n", indexi);
    }
    else
    {
        if (indexi < 1)
        {
            printf("Before Grade 1\n");
        }
        if (indexi > 16)
        {
            printf("Grade 16+\n");
        }
    }
}
