#include "headers.h"

std::wstring formatResult(double result) {
    std::wostringstream oss;
    oss << std::fixed << std::setprecision(15) << result;
    std::wstring str = oss.str();
    str.erase(str.find_last_not_of(L'0') + 1, std::wstring::npos);
    if (str.back() == L'.') {
        str.pop_back();
    }
    return str;
}
    
void calculate(HWND hEdit) {
    try {
        int textLen = GetWindowTextLengthW(hEdit);
        if (textLen == 0) {
            return;
        }
        std::vector<wchar_t> buffer(textLen + 1);
        GetWindowTextW(hEdit, buffer.data(), textLen + 1);
        std::wstring equation(buffer.data());

        std::vector<double> middleResults = {};
        std::stack<std::pair<wchar_t, std::size_t>> brackets;
        for (std::size_t i = 0; i < equation.size(); i++) {
            if (equation[i] == L'(') {
                brackets.push({ equation[i] , i });
            }
            else if (equation[i] == L')') {
                if (brackets.empty()) {
                    throw std::runtime_error("Invalid brackets");
                }
                if (brackets.top().first == L'(') {
                    std::size_t start = brackets.top().second;
                    brackets.pop();
                    std::wstring subEquation = equation.substr(start + 1, i - start - 1);
                    double result = calculateInBrackets(subEquation);
                    std::wstring formattedResult = formatResult(result);
                    equation.replace(start, i - start + 1, formattedResult);
                    i = start + formattedResult.size() - 1;
                }
            }
        }
        if (!brackets.empty()) {
            throw std::runtime_error("Invalid brackets");
        }
        double finalResult = calculateInBrackets(equation);
        SetWindowTextW(hEdit, formatResult(finalResult).c_str());
    }
    catch (const std::invalid_argument& e) {
        std::wstring errorMsg = L"Error: " + std::wstring(e.what(), e.what() + strlen(e.what()));
        SetWindowTextW(hEdit, errorMsg.c_str());
    }
    catch (const std::runtime_error& e) {
        std::wstring errorMsg = L"Error: " + std::wstring(e.what(), e.what() + strlen(e.what()));
        SetWindowTextW(hEdit, errorMsg.c_str());
    }
    catch (const std::exception& e) {
        std::wstring errorMsg = L"Error: " + std::wstring(e.what(), e.what() + strlen(e.what()));
        SetWindowTextW(hEdit, errorMsg.c_str());
    }
    catch (...) {
        SetWindowTextW(hEdit, L"Error");
    }
}