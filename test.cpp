#include <iostream>
#include <unordered_map>

// Hàm chuyển đổi chuỗi chữ cái Latin sang Tiếng Việt
std::string convertToVietnamese(const std::string& input) {
    std::unordered_map<char, std::string> conversionMap = {
        {'a', "a"}, {'w', "ă"}, {'A', "A"}, {'W', "Ă"},
        {'e', "e"}, {'E', "E"},
        {'o', "o"}, {'O', "O"}, {'ow', "ơ"}, {'OW', "Ơ"},
        {'u', "u"}, {'U', "U"}, {'w', "ư"}, {'W', "Ư"},
        {'d', "đ"}, {'D', "Đ"}
    };

    std::string result;
    size_t i = 0;
    while (i < input.length()) {
        char currentChar = input[i];
        auto it = conversionMap.find(currentChar);
        if (it != conversionMap.end()) {
            result += it->second;
            i += (it->first == 'o' || it->first == 'O') ? 2 : 1;
        } else {
            result += currentChar;
            i++;
        }
    }

    return result;
}

// Hàm đếm số lượng chữ cái Tiếng Việt
int countVietnameseLetters(const std::string& input) {
    std::string converted = convertToVietnamese(input);

    int count = 0;
    size_t i = 0;
    while (i < converted.length()) {
        char currentChar = converted[i];
        if (currentChar >= 'a' && currentChar <= 'z') {
            count++;
        }
        i++;
    }

    return count;
}

int main() {
    std::string input;
    std::cout << "Nhập chuỗi chữ cái Latin: ";
    std::cin >> input;

    std::string converted = convertToVietnamese(input);
    int result = countVietnameseLetters(input);

    std::cout << "Chuỗi chữ cái Tiếng Việt: " << converted << std::endl;
    std::cout << "Số lượng chữ cái Tiếng Việt có thể tạo thành: " << result << std::endl;

    return 0;
}

