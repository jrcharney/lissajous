#include "Utils.h"
#include <sstream>
#include <iomanip>

std::string formatFloat(float value, int precision) {
    std::ostringstream out;
    out << std::fixed << std::setprecision(precision) << value;
    return out.str();
}
