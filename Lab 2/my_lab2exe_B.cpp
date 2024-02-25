/*
 *  lab2exe_B.cpp
 *  ENSF 614 Lab 2 Exercise B
 *  Completed by: Jeremy Sugimoto
 *  Submission Date: Sept 27, 2023
 */


#include <iostream>
#include <cstring>
using namespace std;


int my_strlen(const char *s){

int i = 0;
while (s[i]){
    i++;
}  
return i;
}

void my_strncat(char *dest, const char *source, int n){
    int dest_len = 0;
    
    // Calculate the length of the destination string
    while (dest[dest_len] != '\0') {
        dest_len++;
    }

    // Copy characters from source to dest, up to n characters
    for (int i = 0; i < n && source[i] != '\0'; i++) {
        dest[dest_len + i] = source[i];
    }

    // Ensure null-termination of dest
    dest[dest_len + n] = '\0';
}

int my_strcmp(char* str1, char* str2){
    int diff = 0;
    int len = 0;
    while (str1[len] != '\0' && str2[len] != '\0') {
        len++;
    }
    
    for (int i = 0; i< len; i++){
        if (str1[i] != str2[i]){
            diff = int(str1[i]) - int(str2[i]);
            break;
        }
    }
    return diff;


}


int main(void)
{
    char str1[7] = "banana";
    const char str2[] = "-tacit";
    const char* str3 = "-toe";
    
    /* point 1 */
    char str5[] = "ticket";
    char my_string[100]="";
    int bytes;
    int length;
    
    /* using strlen libarary function */
    length = (int) my_strlen(my_string);
    cout << "\nLine 1: my_string length is " << length;
  
    /* using sizeof operator */
    bytes = sizeof (my_string);
    cout << "\nLine 2: my_string size is " << bytes << " bytes.";
   
    /* using strcpy libarary function */
    strcpy(my_string, str1);
    cout << "\nLine 3: my_string contains: " << my_string;
   
    length = (int) my_strlen(my_string);
    cout << "\nLine 4: my_string length is " << length << ".";
   
    my_string[0] = '\0';
    cout << "\nLine 5: my_string contains:\"" << my_string << "\"";
  
    length = (int) my_strlen(my_string);
    cout << "\nLine 6: my_string length is " <<  length << ".";
   
    bytes = sizeof (my_string);
    cout << "\nLine 7: my_string size is still " << bytes << " bytes.";
 
    /* strncat append the first 3 characters of str5 to the end of my_string */
    my_strncat(my_string, str5, 3);
    cout << "\nLine 8: my_string contains:\"" << my_string << "\"";
  
    length = (int) my_strlen(my_string);
    cout << "\nLine 9: my_string length is " << length << ".";
   
    my_strncat(my_string, str2,  4);
    cout << "\nLine 10: my_string contains:\"" << my_string << "\"";
    
    /* strncat append ONLY up ot '\0' character from str3 -- not 6 characters */
    my_strncat(my_string, str3, 6);
    cout << "\nLine 11: my_string contains:\"" << my_string << "\"";
   
    length = (int) my_strlen(my_string);
    cout << "\nLine 12; my_string has " << length << " characters.";

    cout << "\n\nUsing strcmp - C library function: ";
    
    cout << "\n\"ABCD\" is less than \"ABCDE\" ... strcmp returns: " <<
    my_strcmp("ABCD", "ABCDE");

    cout << "\n\"ABCD\" is less than \"ABND\" ... strcmp returns: " <<
    my_strcmp("ABCD", "ABND");
    
    cout << "\n\"ABCD\" is equal than \"ABCD\" ... strcmp returns: " <<
    my_strcmp("ABCD", "ABCD");
 
    cout << "\n\"ABCD\" is less than \"ABCd\" ... strcmp returns: " <<
    my_strcmp("ABCD", "ABCd");

    cout << "\n\"Orange\" is greater than \"Apple\" ... strcmp returns: " <<
    my_strcmp("Orange", "Apple") << endl;
    return 0;
}
