#pragma once

#include <memory>

#include "html_dom.h"

namespace html {
class Parser {
    static std::unique_ptr<HTMLDocument> parse(const std::string& text);
};
}