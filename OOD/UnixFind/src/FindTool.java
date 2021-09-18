import java.util.ArrayList;
import java.util.List;

public class FindTool {
    public List<File> find(String dir, IfileSpecification pattern){
    	List<File> result=new ArrayList<File>();
    	if(dir.charAt(0)!='/') {
    		return result;
    	}
    	File root=FileSystem.getInstance();
    	File cur=root;
    	int index=1;
    	int start=1;
    	while(index<dir.length()) {
    		if(dir.charAt(index)=='/') {
    			String part=dir.substring(start,index);
    			List<File> children=cur.children;
    			File temp=root;
    			for(int i=0;i<children.size();i++) {
    				if(children.get(i).isDir && children.get(i).name.equals(part)) {
    					temp=children.get(i);
    					break;
    				}
    			}
    			if(temp==null) {
    				return result;
    			}
    			cur=temp;
    		}
    	}
    	dfs(cur,pattern,result);
    	return result;
    }
    public void dfs(File root,IfileSpecification pattern,List<File> result) {
    	if(root.isDir==false) {
    		if(pattern.isSatisfiledBy(root)) {
    			result.add(root);
    		}
    		return;
    	}
    	List<File> children=root.children;
    	for(File file:children) {
    		dfs(file,pattern,result);
    	}
    	return;
    }
}
