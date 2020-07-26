/**
 * @file haru_package_builder.hpp
 * @brief defines class HaruPackageBuilder
 * @author Snake52996
 * 
 * Recent changes:
 *     1.1.0    Added private method: convertImageToJpeg, isJpeg
 *     1.0.0	Created
*/
_Pragma("once");
#include<package_builder.hpp>
#include<hpdf.h>
#include<string>
namespace HFormatter::NPackageBuilder{
	/**
	 * @class HaruPackageBuilder
	 * @brief A implementation of PackageBuilder that generates a single pdf file using libharu
	*/
    class HaruPackageBuilder: public PackageBuilder{
        private:
            HPDF_Doc pdf_ = nullptr;        ///< libharu document handle
            HPDF_Page page_ = nullptr;      ///< libharu page handle
            HPDF_Image image_ = nullptr;    ///< libharu image handle
            /// storage for path to create (save) pdf
            fs::path filename_;
            /// frequently used variable: page/image.width
            unsigned int width_;
            /// frequently used variable: page/image.height
            unsigned int height_;
            /**
             * @brief Verify if the image specified by a path is a Jpeg file
             * @param[in] path image_path Path to the specified image
             * @retval true or false
             * @note No verification will be carried out about the image_path.
             * @note Judge by if the file begins with "0xFF 0xD8 0xFF"
            */
            bool isJpeg(const fs::path&)const;
            /**
             * @brief Convert image specified by a path to Jpeg format
             * @param[in] path origin_path Path to the specified image
             * @retval A path where the result is saved
             * @note No verification will be carried out about the origin_path.
             * @note If the specified image is a Jpeg file, origin_path will be returned directly.
            */
            fs::path convertImageToJpeg(const fs::path&)const;
		protected:
            /// implements PackageBuilder::createPackage
			virtual void createPackage(const fs::path&);
            /// implements PackageBuilder::addItem
            virtual void addItem(const std::string&);
            /// implements PackageBuilder::closePackage
            virtual void closePackage();
        public:
            ~HaruPackageBuilder();
    };
}