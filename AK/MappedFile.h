#pragma once

#include "AKString.h"

namespace AK {

class MappedFile {
public:
    MappedFile() { }
    explicit MappedFile(String&& file_name);
    MappedFile(MappedFile&&);
    ~MappedFile();

    bool is_valid() const { return m_map != (void*)-1; }

    void* pointer() { return m_map; }
    const void* pointer() const { return m_map; }
    size_t file_length() const { return m_file_length; }

private:
    String m_file_name;
    size_t m_file_length { 0 };
    int m_fd { -1 };
    void* m_map { (void*)-1 };
};

}

using AK::MappedFile;

