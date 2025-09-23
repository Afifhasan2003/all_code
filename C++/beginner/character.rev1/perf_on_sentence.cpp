//here we will perform various task on sentence
#include <iostream>
#include <cstring>
using namespace std;

void find_longest_word_in_line(string line){
    

    // int n = strlen(line); this wont work for string, just for character array
    int n = line.size();
    int currlen = 0, maxlen = 0;

    int st = 0, maxst = 0;      //st= starting index of the word
                                //maxst= ending index of the word  (ig)
                                
    for (int i = 0; i <= n; i++)   //i<=n must , else last word will go missing
    {

        if (line[i] == ' ' || line[i] == '\0')
        {
            if (currlen > maxlen)
            {
                maxlen = currlen;
                maxst=i;
            }

            currlen = 0;
        }
        else
            currlen++;
    }

    
    cout << maxlen<<endl;

    st=maxst-maxlen;

    for (int i = st; i < maxst; i++)
    {
        cout<<line[i];
    }

}
int main()
{
char line[1000];
    cin.getline(line, 1000);
    int n=strlen(line);

    find_longest_word_in_line(line);
    

    return 0;
}

// ALLAHHH
