#include <vector>
using namespace std;
void generate( vector<string>& result, vector<string>& curlist,
							int leftTags, int rightTags, int len ) {
	if( leftTags > len/2 || rightTags > leftTags ) {
		   return;
	 } 
	if( curlist.size() == len ) {
		   string res = "";
		   for( string elem: curlist ) {
				   res = res + elem;
			 }
		   result.push_back(res);
		   return;
	 }
	 
	 if( leftTags == rightTags ) {
		   curlist.push_back("<div>");
		   generate(result,curlist,leftTags+1,rightTags,len);
		   curlist.pop_back();
		   return;
	 }
	  curlist.push_back("<div>");
		generate(result,curlist,leftTags+1,rightTags,len);
		curlist.pop_back();
	
		curlist.push_back("</div>");
		generate(result,curlist,leftTags,rightTags+1,len);
		curlist.pop_back();
	  return;
	 
}
vector<string> generateDivTags(int numberOfTags) {
  // Write your code here.
	vector<string> result;
	vector<string> curlist;
	generate(result, curlist, 0, 0, 2 * numberOfTags );
  return result;
}


