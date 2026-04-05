#ifndef TXT_PARSER_H
#define TXT_PARSER_H

#include "parser.h"

class TxtParser : public Parser
{
    public:

        /*
        * Parses lines from a txt file, dividing sections of narration and dialog.
        * Saves parsed data into a provided Book.

        * @param[in] istr
        *   input stream (typically a file) to be parsed

        * @param[in] book
        *   Book class where parsed information will be stored.
        */
        
        void segment_lines(std::istream& istr, Book& book);


};

#endif