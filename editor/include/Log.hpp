#pragma once

#include <vector>
#include <string>

class Ui_LevelEditor;

namespace Ui {
    class LevelEditor;
}

class Line {
public:
    Line(std::string tag, std::string content) : mTag(tag), mContent(content) {}

    std::string getTag() {
        return mTag;
    }

    std::string getContent() {
        return mContent;
    }

private:
    std::string mTag;
    std::string mContent;
};

class Log {
public:
    Log() = default;

    static Log* getInstance() {
        if(mInstance == nullptr){
            mInstance = new Log();
        }
        return mInstance;
    }

    static std::string println(std::string tag, std::string content);

    static std::vector<Line> getLines() { return mLines; }

    static void setUiReference(Ui::LevelEditor* ref);

    static Ui::LevelEditor* getUiReference();

private:
    static Log* mInstance;
    static Ui::LevelEditor* Ui_Ref;
    static std::vector<Line> mLines;
    static std::vector<std::string> mFormatedLines;
};
