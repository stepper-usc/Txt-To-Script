#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <string_view>
#include <vector>
#include <set>

struct Chapter {
    std::set<std::string> characters;
    std::vector<std::string> lines;
    std::vector<int> dialog_indexes;
    std::string name;
};

class Book {
    public: 
        Book();
        ~Book();
        void create_chapter(std::string chapter_name);
        void add_line_to_chapter(Chapter* chapter, std::string str);
        Chapter* get_chapter(std::string name);
        void display_book();

    private:
        std::vector<Chapter*> chapters_;
    
};

#endif