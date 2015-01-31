//
//  main.cpp
//  CharSorter
//
//  Created by Vinod Gupta on 1/31/15.
//  Copyright (c) 2015 Vinod Gupta. All rights reserved.
//

#include <iostream>
#include <string>
class CharSorter
{
public:
    CharSorter()
    {
        Reset();
    }
    virtual ~CharSorter()
    {
        
    }

    
    void CountChars(std::string sentence)
    {
        Reset();
        for(std::string::const_iterator itr = sentence.begin(); itr != sentence.end(); ++itr)
        {
            char c = *itr;
            if(c >='A' && c <='Z')
            {
                c = 'a' + (c - 'A');
            }
            int pos=-1;
            if( c >= 'a' && c <= 'z')
            {
                pos = c - 'a';
                _chars[pos] = _chars[pos] + 1;
            }
            
        }
    }
    
    void PrintChars()
    {
        for(int i=0;i<26;++i)
        {
            for(int j =0;j<_chars[i];++j)
            {
                std::cout<<(char) ('a' + i);
            }
        }
        std::cout<<std::endl;
    }
private:
    void Reset()
    {
        for(int i=0;i<26;++i)
        {
            _chars[i] = 0;
        }
    }
    char _chars[26];
};

int main(int argc, const char * argv[]) {
    std::string sentence = "When not studying nuclear physics, Bambi likes to play beach volleyball.";
    
    CharSorter sorter;
    sorter.CountChars(sentence);
    sorter.PrintChars();
    
    //Expected "aaaaabbbbcccdeeeeeghhhiiiiklllllllmnnnnooopprsssstttuuvwyyyy"
    //Actual   "aaaaabbbbcccdeeeeeghhhiiiiklllllllmnnnnooopprsssstttuuvwyyyy"
    return 0;
}
