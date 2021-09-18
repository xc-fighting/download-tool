import java.util.List;

public class FileSystem {
    public static File root=null;
    public static File getInstance() {
    	synchronized(FileSystem.class) {
    		if(root==null) {
        		root=new File(true,0,"/","");
        		System.out.println("root create finish");
        	}
    	}
    	return root;
    	
    }
    public FileSystem() {
    	
    }
    public File mkdir(String path) {
    	File cur=root;
    	char[] chStr=path.toCharArray();
    	if(chStr[0]!='/') {
    		return null;
    	}
    	int start=1;
    	int index=1;
    	File res=null;
    	while(index<chStr.length) {
    		if(chStr[index]=='/') {
    			String part=path.substring(start,index);
    			
    			File target=null;
    			target=findEntry(cur,part);
    			if(target==null) {
    				target=new File(true,0,part,"");
    				cur.children.add(target);
    			}
    			cur=target;
    			start=index+1;
    			if(start==chStr.length) {
    				res=cur;
    				break;
    			}
    		}
    		index++;
    	}
    	if(res==null) {
    		if(start<path.length()) {
    			String part=path.substring(start);
    			File target=null;
    			target=findEntry(cur,part);
    			if(target==null) {
    				target=new File(true,0,part,"");
    				cur.children.add(target);
    			}
    			res=cur;
    			return res;
    		}
    		return null;
    	}
    	return res;
    	
    }
    public void printTree(File root,int depth) {
    	 if(root==null) {
    		 return;
    	 }
    	 String spaceString="";
    	 for(int i=0;i<depth;i++) {
    		 spaceString+=" ";
    	 }
    	 if(root.isDir==false) {
    		 System.out.println(spaceString+"file:"+root.name+"."+root.format+"--"+root.size);
    		 return;
    	 }
    	 System.out.println(spaceString+"dir:"+root.name);
    	 List<File> children=root.children;
    	 for(File child:children) {
    		 printTree(child,depth+1);
    	 }
    	 return;
    	 
    }
    // the format for dirpath /abc/def/
    public int createFile(String dirPath, String filename,String format,int size) {
    	//0 mean success
    	//2 mean dirpath not valid
    	if(dirPath.charAt(0)!='/') {
    		return 2;
    	}
    	int index=1;
    	int start=1;
    	File cur=root;
    	while(index<dirPath.length()) {
    		if(dirPath.charAt(index)=='/') {
    			String part=dirPath.substring(start,index);
    			File nextEntry=findEntry(cur,part);
    			if(nextEntry==null) {
    				return 2;
    			}
    			else {
    				cur=nextEntry;
    				start=index+1;
    			}
    		}
    		index++;
    	}
    	File newFile=new File(false,size,filename,format);
    	cur.children.add(newFile);
    	return 0;
    }
    
    
    private File findEntry(File root,String part) {
    	List<File> children=root.children;
		File target=null;
		for(int i=0;i<children.size();i++) {
			 File child=children.get(i);
			 if(child.name.equals(part)) {
				 target=child;
				 break;
			 }
		}
		return target;
    }
}
