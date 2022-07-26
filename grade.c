#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text); // To count letters
int count_words(string text); // To count words
int count_sentences(string text); // To count sentences

int main(void)
{
    // Getting input
    string text = get_string("Text: ");

    // Counting letters, word and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sen = count_sentences(text);
    printf("%d %d %d", letters, words, sen);
    // Calculating result
    float L = ((float)letters / words) * 100;
    float S = ((float)sen / words) * 100;
    double index = 0.0588 * L - 0.296 * S - 15.8;
    /* round function returns a double rounded to the nearest integer. We may safely cast that value to a long (or an int if it fits) */
    int ans = (int)round(index);

    // Printing appropriate grade
    if (ans < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (ans >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", ans);
    }
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isupper(text[i]) || islower(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    // We return count++ because last word of text is not counted
    return ++count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;

}
