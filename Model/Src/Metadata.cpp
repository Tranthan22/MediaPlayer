#include "Metadata.hpp"
#include "MetadataView.hpp"

TagLib::FileRef Metadata::getfileRef()
{
    TagLib::FileRef fileRef(file_Path.c_str());
    return fileRef;
}
void Metadata::set_FilePath(string file_Path)
{
    this->file_Path =file_Path;
}

