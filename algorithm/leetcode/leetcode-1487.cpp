class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> result;
        unordered_map<string,int> foldernames;
        for( int index = 0; index < names.size(); index++ ) {
            string folder = names[index];
            if( foldernames.find(folder) == foldernames.end() ) {
                foldernames[folder] = 0;
                result.push_back(folder);
            }
            else { 
                string newfolder = folder;
                int min = foldernames[folder];
                while( foldernames.find(newfolder) != foldernames.end() ) {
                    min = min + 1;
                    newfolder = folder + "(" + to_string(min) + ")";
                   // cout<<newfolder<<endl;
                }
                foldernames[folder] = min;
                foldernames[newfolder] = 0;
                result.push_back(newfolder);
            }
            
        }
        return result;
    }
};