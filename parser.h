#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <istream>
#include "book.h"

class Parser 
{
    public:

        Parser() = default;
        virtual ~Parser() = default;

        /*
        * Parses lines from a istream, dividing sections of narration and dialog.
        * Saves parsed data into a provided Book.

        * @param[in] istr
        *   input stream (typically a file) to be parsed

        * @param[in] book
        *   Book class where parsed information will be stored.
        */

        virtual void segment_lines(std::istream& istr, Chapter& book) = 0;


};

#endif