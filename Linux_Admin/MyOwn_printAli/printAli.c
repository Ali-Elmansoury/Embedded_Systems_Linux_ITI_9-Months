#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define STD_OUT_FD  1

#define BUFFER_SIZE 512

void* memoryCopy(void* dest, void* src, size_t size){
    char* d = (char*) dest;
    char* s = (char*) src;

    while (size--)
    {
        *d++ = *s++;
    }

    return dest;
}

unsigned long stringLen(char data[])
{
    unsigned long count = 0;
    while (*data != '\0')
    {
        data++;
        count++;
    }
    return count;
}

void printAli(char* format, ...)
{
    //Step 1: Pointer to a list of variable arguments
    va_list args;

    //Step 2: Intialization of pointer to list by values passed as optional args, 1st arg is the pointer to list, 2nd arg is tha last mandatory arg in the function
    va_start(args, format);

    char buffer[BUFFER_SIZE];
    int bufferIndex = 0;

    while (*format != '\0')
    {
        char temp[BUFFER_SIZE/2];
        int length = 0;
        if (*format == '%' )
        {
            switch (*(++format))
            {
            case 'd':
                //Step 3: The optional arguments can finally be accessed individually by repeating the following command and storing them in individual variables, 1st argument is ptr to list, 2nd is the EXPECTED type of argument (it must be correct else it will cause an error)
                int intVal = va_arg(args, int);
                length = sprintf(temp, "%d", intVal);
                break;
            
            case 'c':
                //Step 3: The optional arguments can finally be accessed individually by repeating the following command and storing them in individual variables, 1st argument is ptr to list, 2nd is the EXPECTED type of argument (it must be correct else it will cause an error)
                char charVal = (char)va_arg(args, int);
                /*In a variadic function, arguments smaller than int (like char or short) are automatically promoted to int when passed. This is due to the default argument promotion rules in C.
                Therefore, to retrieve a char using va_arg, you must use int as the type.
                Even though the original argument is a char, it’s promoted to int when passed to the function.
                You must cast the retrieved int back to char to get the correct value.*/
                length = sprintf(temp, "%c", charVal);
            break;

            case 'f':
                //Step 3: The optional arguments can finally be accessed individually by repeating the following command and storing them in individual variables, 1st argument is ptr to list, 2nd is the EXPECTED type of argument (it must be correct else it will cause an error)
                /*Also float is promoted to double so it must be casted*/
                float floatVal = (float)va_arg(args, double);
                length = sprintf(temp, "%f", floatVal);
            break;

            case 's':
                //Step 3: The optional arguments can finally be accessed individually by repeating the following command and storing them in individual variables, 1st argument is ptr to list, 2nd is the EXPECTED type of argument (it must be correct else it will cause an error)
                char* stringVal = va_arg(args, char*);
                length = stringLen(stringVal);
                memoryCopy(temp, stringVal, length);
            break;

            default:
                if (bufferIndex < BUFFER_SIZE - 2) {
                buffer[bufferIndex++] = '%';
                buffer[bufferIndex++] = *format;
                }           
                break;
            }

            if ((bufferIndex + length) < sizeof(buffer))
            {
                memoryCopy(&buffer[bufferIndex], temp, length);
                bufferIndex += length;
            }
            
        }
        else
        {
            if (bufferIndex < BUFFER_SIZE - 1)
            {
                buffer[bufferIndex++] = *format;
            }
        }
        
        format++;
    }

    //Step 4: Clean up! Reset the list pointer to NULL upon exiting. Note that skipping this step will result in 𝒖𝒏𝒅𝒆𝒇𝒊𝒏𝒆𝒅 𝒃𝒆𝒉𝒂𝒗𝒊𝒐𝒖𝒓.
    va_end(args);

    //Step 5: Write the buffer to the standard output file descriptor
    write(STD_OUT_FD, buffer, bufferIndex);
}

int main(int argc, char* argv[])
{
    printAli("Integer: %d, Character: %c, Float: %f, String: %s\n", 5, 'A', 3.14, "Hello!");

    return 0;
}