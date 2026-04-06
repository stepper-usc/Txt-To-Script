#include <iostream>
#include <fstream>
#include "book.h"
#include "parser.h"
#include "txt_parser.h"

int main(){
    std::ifstream f = std::ifstream("test-files/segment.txt");
    Parser* p = new TxtParser();
    Chapter c("test_chapter");

    p->segment_lines(f,c);

    std::vector<std::string> story = c.get_story_lines();
    for (auto line : story){
        std::cout << line << std::endl;
    }

}