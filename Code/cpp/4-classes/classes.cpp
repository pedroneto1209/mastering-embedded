#include <iostream>

class Console {
  private:
    int m_level = infoLevel;

  public:
    const int errorLevel = 0;
    const int warningLevel = 1;
    const int infoLevel = 2;

    void setLevel(int level) { m_level = level; }

    void log(int type, const char string[]) {
        if (type <= m_level) {

            std::cout << ((type == infoLevel)      ? "INFO"
                          : (type == warningLevel) ? "WARNING"
                                                   : "ERROR")
                      << " | ";

            std::cout << string << std::endl;
        }
    }
};

int main() {
    Console console;

    console.log(console.infoLevel, "test info");
    console.log(console.warningLevel, "test warning");
    console.log(console.errorLevel, "test error");
    console.setLevel(console.errorLevel);
    console.log(console.infoLevel, "test info");
    console.log(console.warningLevel, "test warning");
    console.log(console.errorLevel, "test error");
    console.setLevel(console.warningLevel);
    console.log(console.infoLevel, "test info");
    console.log(console.warningLevel, "test warning");
    console.log(console.errorLevel, "test error");
    console.setLevel(console.infoLevel);
    console.log(console.infoLevel, "test info");
    console.log(console.warningLevel, "test warning");
    console.log(console.errorLevel, "test error");
}