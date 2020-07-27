_Pragma("once");
#include<file_operator.hpp>
namespace HFormatter::NFileOperator{
    class MiaoyueFileOperator: public FileOperator{
        public:
            virtual void operateItem(PartInfo&);
    };
}