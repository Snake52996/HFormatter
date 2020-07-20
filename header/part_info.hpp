_Pragma("once");
#include<string>
#include<vector>
using std::string;
using std::vector;
namespace HFormatter::NPartInfo{
    class PartInfo{
        private:
            string part_title_;
            vector<string> part_items_;
        public:
			PartInfo(const string&);
			virtual void setTitle(const string&);
            virtual const string& getTitle()const;
            virtual void addItem(const string&);
            virtual const string& getItem(const unsigned int)const;
            virtual const vector<string>& getItems()const;
    };
}