#ifndef MEDIAFILEVIEW_HPP
#define MEDIAFILEVIEW_HPP

#include "MediaFile.hpp"
#include "MetadataView.hpp"
#include "main.hpp"


class MediaFileView
{
private:
    //Path:
    size_t utf8_strlen(const std::string& str) {
        // Chuyển đổi từ UTF-8 sang wstring (UTF-32)
        std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
        std::u32string u32_str = converter.from_bytes(str);

        // Trả về kích thước của chuỗi UTF-32
        return u32_str.length();
    }
    // Hàm cắt chuỗi UTF-8 nếu dài hơn độ dài tối đa
    std::string truncate_utf8(const std::string& str, size_t max_length) {
        std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
        std::u32string u32_str = converter.from_bytes(str);

        if (u32_str.length() > max_length) {
            u32_str = u32_str.substr(0, max_length);
        }

        return converter.to_bytes(u32_str);
    }
    // Hàm để căn chỉnh trái một chuỗi UTF-8 với độ rộng cố định
    std::string left_align(const std::string& str, size_t width) {
        std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
        std::u32string u32_str = converter.from_bytes(str);

        size_t length = u32_str.length();
        if (length >= width) {
            return converter.to_bytes(u32_str.substr(0, width));
        }

        std::string result = converter.to_bytes(u32_str);
        result.append(width - length, ' '); // Thêm khoảng trắng cho đủ độ rộng
        return result;
    }
    std::string secondsToTimeFormat(int seconds) {
        int hours = seconds / 3600;
        seconds %= 3600;
        int minutes = seconds / 60;
        seconds %= 60;

        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << hours << ":"
            << std::setw(2) << std::setfill('0') << minutes << ":"
            << std::setw(2) << std::setfill('0') << seconds;

        return oss.str();
    }
public:
    MediaFileView()=default;
    ~MediaFileView()=default;
    
    void display_MediaFile(vector<MediaFile*>& songs, size_t currentpage);
    
    void displaySongsPerPage(vector<MediaFile*>& songs, size_t& currentpage);
    void Invalid_choice();
    int check_choice(vector<MediaFile*>& songs, size_t& currentPage);
};

#endif /*MEDIAFILEVIEW_HPP*/

