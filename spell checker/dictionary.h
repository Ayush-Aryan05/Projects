#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

//class implementing the tries data structure

class tries
{
    bool value;     //marker to indicate leaf node
    tries* pointers[26];    //pointers to the various characters of english alphabet

public:
    tries()
    {
        //initialises all pointers as null
        value = 0;
        for(int i =0 ; i<26; i++)
            pointers[i] = NULL;
    }

    //This function adds a word to the trie
    void add(string s)
    {
        tries* trav = this;

        for(int i = 0; i<s.length(); i++)
        {
            int pos = tolower(s[i]-'a');
            if(trav->pointers[pos]==NULL)
                trav->pointers[pos] = new tries;
            trav = trav->pointers[pos];
        }

        trav->value = true;
    }

    //This function searches a word in the trie
    bool searchtries(string word, int i)
    {
        if(i==word.length())
            return value;

        if(pointers[tolower(word[i])-'a']==NULL)
            return false;

        return pointers[tolower(word[i])-'a']->searchtries(word,i+1);
    }

    //This function deletes a word from the trie
    void deletetries()
    {
        for(int i = 0; i<26; i++)
        {
            if(pointers[i]!=NULL)
                pointers[i]->deletetries();
        }
        delete this;
    }
};

//A class representing dictionary
class dictionary
{
public:
    string dict; //contains the file name for text file containing the dictionary words
    tries* root;    //a pointer to the trie
    dictionary(string file)
    {
        dict = file;
        root = NULL;
    }

    //This is used to load the words from the file to memory. Returns true if the operation is successful, else false
    bool load()
    {
        fstream f;
        f.open(dict,ios::in);
        if(!f.is_open())
        {
            return false;
        }

        root = new tries;
        string str;

        while(!f.eof())
        {
            f>>str;
            root->add(str);
        }

        f.close();
        return true;
    }

    //This is used to free the memory used by the trie data structure
    void unload()
    {
        root->deletetries();
    }

    //This checks the given word in the dictionary file and returns true if present else false;
    bool check(string word)
    {
        return root->searchtries(word,0);
    }
};