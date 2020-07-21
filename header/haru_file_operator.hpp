_Pragma("once");
#include<file_operator.hpp>
#include<vector>
namespace HFormatter::NFileOperator{
    class HaruFileOperator: public FileOperator{
        private:
            std::vector<int> params_;
        public:
            HaruFileOperator();
			virtual void operateItem(PartInfo&);
    };
}