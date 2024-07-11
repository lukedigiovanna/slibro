#pragma once

#include <vector>
#include <string>

// represents an html dom tree

namespace html {
class HTMLElement {
private:
    std::string tagName;
    std::vector<HTMLElement> children;
public:
    HTMLElement();
};

#define DEF_ELEMENT(NAME) class HTML##NAME##Element : public HTMLElement {};

DEF_ELEMENT(P)
DEF_ELEMENT(H1)
DEF_ELEMENT(H2)
DEF_ELEMENT(H3)
DEF_ELEMENT(H4)
DEF_ELEMENT(H5)
DEF_ELEMENT(Div)
DEF_ELEMENT(Title)

#undef DEF_ELEMENT

class HTMLDocument {
private:
    HTMLElement head;
    HTMLElement body;
public:
    const std::string& title() const;
};
}
