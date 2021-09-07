class Solution {
public:
    /**
     * @param path: the original path
     * @return: the simplified path
     */
    string simplifyPath(string &path) {
        // write your code here
        stack<string> pathstack;
        pathstack.push("/");
        int len = path.size();
        if(path[len-1]=='/')
        {
            path = path.substr(0,len-1);
        }
        int index = 1;
        bool invalid = false;
        while(index < path.size())
        {
            while(index < path.size() && path[index] == '/')
            {
                index++;
            }
            if(index == path.size())
            {
                break;
            }
            if(path[index]=='.')
            {
                if(index+1 < path.size() && path[index+1] == '.')
                {
                    string topstr = pathstack.top();
                    if(topstr.compare("/")!=0)
                    {
                        pathstack.pop();
                    }
                    index += 2;
                    if(index < path.size() && path[index] != '/')
                    {
                        invalid = true;
                        break;
                    }
                }
                else
                {
                    index++;
                    if(index < path.size() && path[index] != '/')
                    {
                        invalid = true;
                        break;
                    }
                }
            }
            else
            {
                int start = index;
                while(index < path.size() && path[index] != '/')
                {
                    index++;
                }
                string component = path.substr(start,index-start);
                cout<<component<<endl;
                pathstack.push(component);
            }
        }
        if(invalid)
        {
           
            return path;
        }
        string result = "";
        while(pathstack.empty()==false)
        {
            if(pathstack.top() != "/")
            {
                result = "/" + pathstack.top() + result;
            }
            
            pathstack.pop();
        }
        if(result == "")
        {
            return "/";
        }
        return result;
    }
};