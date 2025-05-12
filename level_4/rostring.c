#include <unistd.h>
#include <stdlib.h>

// Function to check if a character is a space or tab
int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

// Function to write a string to stdout
void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
        write(1, &str[i++], 1);
}

// Function to write a single character to stdout
void ft_putchar(char c)
{
    write(1, &c, 1);
}

// Main rostring function
void rostring(char *str)
{
    int i = 0;
    int start_first = -1;
    int end_first = -1;
    
    // Skip leading spaces
    while (str[i] && is_space(str[i]))
        i++;
    
    // Find the first word
    if (str[i])
    {
        start_first = i;
        while (str[i] && !is_space(str[i]))
            i++;
        end_first = i;
    }
    
    // Skip spaces after the first word
    while (str[i] && is_space(str[i]))
        i++;
    
    // Print all words after the first word
    int word_printed = 0;
    while (str[i])
    {
        // Print a word
        if (!is_space(str[i]))
        {
            // Add space between words if needed
            if (word_printed)
                ft_putchar(' ');
            
            // Print the word
            while (str[i] && !is_space(str[i]))
            {
                ft_putchar(str[i]);
                i++;
            }
            word_printed = 1;
        }
        else
            i++;
    }
    
    // Print the first word if it exists
    if (start_first != -1)
    {
        // Add space before the first word if we've printed other words
        if (word_printed)
            ft_putchar(' ');
        
        // Print the first word
        for (i = start_first; i < end_first; i++)
            ft_putchar(str[i]);
    }
}

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        rostring(argv[1]);
    }
    ft_putchar('\n');
    return (0);
}
