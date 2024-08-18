#include "headers.h"

double calculateOperation(double a, double b, wchar_t op) {
    switch (op) {
    case L'+': return a + b;
    case L'-': return a - b;
    case L'*': return a * b;
    case L'/':
        if (b != 0) return a / b;
        else throw std::runtime_error("Division by zero");
    default: throw std::invalid_argument("Invalid operator");
    }
}

double calculateInBrackets(std::wstring& equation) {
    std::vector<double> numbers;
    std::vector<wchar_t> operators;
    std::wstring subnum = L"";
    bool lastWasOperator = true;

    for (wchar_t curChar : equation) {
        if (iswdigit(curChar) || curChar == L'.') {
            subnum += curChar;
            lastWasOperator = false;
        }
        else if (curChar == L'+' || curChar == L'-' || curChar == L'/' || curChar == L'*') {
            if (!subnum.empty()) {
                numbers.push_back(std::stod(subnum));
                subnum.clear();
            }
            else if (lastWasOperator && curChar == L'-') {
                subnum = L"-";
                continue;
            }
            operators.push_back(curChar);
            lastWasOperator = true;
        }
        else if (!iswspace(curChar)) {
            throw std::invalid_argument("Invalid character in equation");
        }
    }

    if (!subnum.empty()) {
        numbers.push_back(std::stod(subnum));
    }

    if (numbers.size() != operators.size() + 1) {
        throw std::invalid_argument("Mismatched numbers and operators");
    }

    for (size_t i = 0; i < operators.size(); i++) {
        if (operators[i] == L'*' || operators[i] == L'/') {
            numbers[i] = calculateOperation(numbers[i], numbers[i + 1], operators[i]);
            numbers.erase(numbers.begin() + i + 1);
            operators.erase(operators.begin() + i);
            i--;
        }
    }

    double result = numbers[0];
    for (size_t i = 0; i < operators.size(); i++) {
        result = calculateOperation(result, numbers[i + 1], operators[i]);
    }

    return result;
}