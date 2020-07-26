/**
 * @file haru_package_builder.cpp
 * @brief implements methods in class HaruPackageBuilder
 * @author Snake52996
 * 
 * Recent changes:
 *     1.1.0    Convert image format to jpeg before packing. Add depedency: stb
 *     1.0.0	Created
*/
#include<haru_package_builder.hpp>
#include<hpdf.h>
#define STB_IMAGE_IMPLEMENTATION        ///< required by stb library
#include<stb/stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION  ///< required by stb library
#include<stb/stb_image_write.h>
#include<string>
#include<fstream>
using HFormatter::NPackageBuilder::HaruPackageBuilder;
using std::string;
bool HaruPackageBuilder::isJpeg(const fs::path& image_path)const{
    // open given file in binary mode
    std::ifstream image_file(image_path, std::ios::binary);
    // judge by if the file begins with "0xFF 0xD8 0xFF"
    if(
        image_file.get() == 0xff &&
        image_file.get() == 0xd8 &&
        image_file.get() == 0xff
    ) return true;
    return false;
}
fs::path HaruPackageBuilder::convertImageToJpeg(const fs::path& origin_path)const{
    // if the specified image is a Jpeg file, return origin_path directly
    if(isJpeg(origin_path)) return origin_path;
    // construct new filename
    fs::path result(origin_path);
    result.replace_extension(".jpg");
    // use std library to convert image
    static int x;
    static int y;
    static int n;
    static unsigned char* image_data = stbi_load(origin_path.c_str(), &x, &y, &n, 0);
    stbi_write_jpg(result.c_str(), x, y, n, image_data, 100);   // full quality
    return result;
}
void HaruPackageBuilder::createPackage(const fs::path& package){
    pdf_ = HPDF_New(NULL, NULL);
    filename_ = package;
	filename_ += ".pdf";
    // disable compression
    HPDF_SetCompressionMode(pdf_, HPDF_COMP_NONE);
    // disable outline and thumbnail pane
    HPDF_SetPageMode(pdf_, HPDF_PAGE_MODE_USE_NONE);
}
void HaruPackageBuilder::addItem(const string& item_path){
    // convert image to jpeg
    static fs::path jpeg_path = convertImageToJpeg(item_path);
    // add new page to pdf file
    page_ = HPDF_AddPage(pdf_);
    // load image from given path
    image_ = HPDF_LoadJpegImageFromFile(pdf_, jpeg_path.c_str());
    width_ = HPDF_Image_GetWidth(image_);
    height_ = HPDF_Image_GetHeight(image_);
    HPDF_Page_SetWidth(page_, width_);
    HPDF_Page_SetHeight(page_, height_);
    HPDF_Page_DrawImage(page_, image_, 0, 0, width_, height_);
}
void HaruPackageBuilder::closePackage(){
    HPDF_SaveToFile(pdf_, filename_.c_str());
    HPDF_Free(pdf_);
    pdf_ = nullptr;
	page_ = nullptr;
	image_ = nullptr;
}
HaruPackageBuilder::~HaruPackageBuilder(){
    // In case instance destructed with a not nullptr document handle,
    // close (save) the pdf file.
	if(pdf_ != nullptr) closePackage();
}