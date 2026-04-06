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

    Chapter(std::string name){
        this->name = name;
    }

    void add_line_to_chapter(std::string str){
        lines.push_back(str);
    }

    void add_dialog_index(int index){
        dialog_indexes.push_back(index);
    }

    void add_character(std::string character_name){
        characters.insert(character_name);
    }

    std::string_view get_name(){
        return this->name;
    }

    std::set<std::string>& get_characters(){
        return this->characters;
    }

    std::vector<int>& get_dialog_indexes(){
        return this->dialog_indexes;
    }

    std::vector<std::string>& get_story_lines(){
        return this->lines;
    }
    
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