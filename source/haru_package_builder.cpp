#include<haru_package_builder.hpp>
#include<hpdf.h>
#include<string>
using HFormatter::NPackageBuilder::HaruPackageBuilder;
using std::string;
void HaruPackageBuilder::createPackage(const fs::path& package){
    pdf_ = HPDF_New(NULL, NULL);
    filename_ = package;
	filename_ += ".pdf";
    HPDF_SetCompressionMode(pdf_, HPDF_COMP_NONE);
    HPDF_SetPageMode(pdf_, HPDF_PAGE_MODE_USE_NONE);
}
void HaruPackageBuilder::addItem(const string& item_path){
    page_ = HPDF_AddPage(pdf_);
    image_ = HPDF_LoadJpegImageFromFile(pdf_, item_path.c_str());
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
	if(pdf_ != nullptr) closePackage();
}