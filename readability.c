#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    //prompt user for text
    string text = get_string("text: ");

    //count the number of letters
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }
    }

    //count the number of words
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }

    }

    //count the number of sentences
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }

    }

    //Use Colemon-Liau formula to calculate the grade level
    float calculation = (0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8;

    int index = round(calculation);

    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }

    else if (index >= 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
    else
    {
        printf("Grade %i\n", index);
        return 0;
    }


}
