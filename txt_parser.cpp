#include "txt_parser.h"
#include <iostream>
#include <array>

typedef enum { NARRATION, DIALOG } PARSE_STATE_T;
constexpr std::array<std::string_view, 2> begin_quotation = {"\"", "“"};
constexpr std::array<std::string_view, 2> end_quotation = {"\"", "”"};

void TxtParser::segment_lines(std::istream& istr, Chapter& chapter){

    std::string line = "";
    PARSE_STATE_T story_state = NARRATION;

    while(std::getline(istr, line)){
        std::cout << line << '\n';
        chapter.add_line_to_chapter(line);
    }



    // search within the found string, searching for dialog

}
