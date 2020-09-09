#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    //length of input
    string num = argv[1];
    int num_length = strlen(num);
    
    //check for invalid entries
    int j = 0;
    
    for (int i = 0; i < num_length; i++)
    {
        if (isalpha(num[i]) || ispunct(num[i]) || isspace(num[i]))
        {
            j++;
        }
        
    }
    
    //Success
    if (argc == 2 && j == 0)
    {
        //convert string into int
        int x = atoi(num);
        int p = x;
        
        if (x >= 27)
        {
            p = x % 26;
        }
        
        //Get desried message
        string text = get_string("plaintext: ");
        
        //calculate message length
        int text_length = strlen(text);
        
        printf("ciphertext: ");
        
        for (int i = 0; i < text_length; i++)
        {
            if (isalpha(text[i]))
            {

                if (isupper(text[i]))
                {
                    int o = text[i] + p;
                    
                    if (o > 90)
                    {
                        o = o - 26;
                    }
                    
                    printf("%c", o);
                }
                
                else if (islower(text[i]))
                {
                    int o = text[i] + p;
                    
                    if (o > 122)
                    {
                        o = o - 26;
                    }
                    
                    printf("%c", o);
                }
                
                else
                {
                    printf("%c", text[i] + p);
                }
                
            }
            
            else 
            {
                printf("%c", text[i]);
            }
        }
        
        printf("\n");
        return 0;
    }
    
    //Failure
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
}
