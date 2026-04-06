#include "txt_parser.h"
#include <iostream>
#include <array>
#include <stack>
#include <string_view>

typedef enum { NARRATION, DIALOG } PARSE_STATE_T;
constexpr std::array<std::string_view, 2> begin_quotation = {"\"", "“"};
constexpr std::array<std::string_view, 2> end_quotation = {"\"", "”"};

bool matches_token(std::string::const_iterator it,
                   std::string::const_iterator end,
                   std::string_view token)
{
    if (std::distance(it, end) < static_cast<long>(token.size())) {
        return false;
    }

    for (size_t i = 0; i < token.size(); ++i) {
        if (*(it + i) != token[i]) {
            return false;
        }
    }
    return true;
}

void TxtParser::segment_lines(std::istream& istr, Chapter& chapter)
{
    std::string line = "";
    PARSE_STATE_T story_state = NARRATION;
    int quote_depth = 0;
    int index = 0;
    std::string line_to_add = "";

    while (std::getline(istr, line)) {
        while (!line.empty() &&
               (line[0] == ' ' || matches_token(line.cbegin(), line.cend(), "　"))) {
            if (line[0] == ' ') {
                line.erase(0, 1);
            } else {
                line.erase(0, std::string("　").size());
            }
        }

        for (std::string::const_iterator it = line.cbegin(); it != line.cend(); ) {
            bool matched = false;

            if (story_state == NARRATION) {
                for (std::string_view bq : begin_quotation) {
                    if (matches_token(it, line.cend(), bq)) {
                        if (!line_to_add.empty()) {
                            chapter.add_line_to_chapter(line_to_add);
                            line_to_add.clear();
                            index++;
                        }

                        story_state = DIALOG;
                        quote_depth = 1;

                        std::advance(it, bq.size());
                        matched = true;
                        break;
                    }
                }

                if (matched) {
                    continue;
                }

                line_to_add += *it;
                ++it;
            }
            else {
                for (std::string_view eq : end_quotation) {
                    if (matches_token(it, line.cend(), eq)) {
                        quote_depth--;

                        std::advance(it, eq.size());
                        matched = true;

                        if (quote_depth == 0) {
                            chapter.add_line_to_chapter(line_to_add);
                            chapter.add_dialog_index(index);
                            line_to_add.clear();
                            index++;
                            story_state = NARRATION;
                        }
                        break;
                    }
                }

                if (matched) {
                    continue;
                }

                for (std::string_view bq : begin_quotation) {
                    if (matches_token(it, line.cend(), bq)) {
                        line_to_add += std::string(bq);
                        quote_depth++;
                        std::advance(it, bq.size());
                        matched = true;
                        break;
                    }
                }

                if (matched) {
                    continue;
                }

                line_to_add += *it;
                ++it;
            }
        }
    }

    if (!line_to_add.empty()) {
        chapter.add_line_to_chapter(line_to_add);

        if (story_state == DIALOG) {
            chapter.add_dialog_index(index);
        }
    }
}