_Pragma("once");
#include<path_completer.hpp>
#include<string>
#include<vector>
using std::string;
using std::vector;
using HFormatter::NPathCompleter::PathCompleter;
namespace HFormatter::NPartInfo{
    class PartInfo{
        protected:
            string part_title_;
            vector<string> part_items_;
        public:
			PartInfo(const string&);
			virtual void setTitle(const string&);
            virtual const string& getTitle()const;
            virtual void addItem(const string&);
            virtual const string& getItem(const unsigned int)const;
            virtual const vector<string>& getItems()const;
            virtual vector<string>& getItems();
            virtual void updateItems(PathCompleter&);
    };
}