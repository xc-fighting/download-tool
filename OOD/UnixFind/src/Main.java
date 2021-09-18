import java.util.List;

public class Main {

	
	public static void main(String[] args) {
		FileSystem fileSys=new FileSystem();
		FileSystem.getInstance();
	    fileSys.mkdir("/tmp/test1/pics");
	    fileSys.mkdir("/var/usr/data");
	    fileSys.mkdir("/tmp/test1/etc");
	    fileSys.mkdir("/tmp/test1/etc/chen");
	    fileSys.createFile("/tmp/test1/pics/", "demo", "jpeg", 250);
	    fileSys.createFile("/tmp/test1/pics/", "scene","png", 100);
	    fileSys.createFile("/tmp/test1/etc/", "config", "db", 56);
	    fileSys.createFile("/tmp/test1/etc/", "newcfg", "cfg", 30);
	    fileSys.createFile("/var/usr/data/", "firmware", "bin", 500);
	    fileSys.createFile("/tmp/test1/etc/chen/", "chendata", "cfg", 60);
	    
	    fileSys.printTree(fileSys.root, 0);
	    
	    fileCompositeSpecification pattern1=new fileSizeGreatEqual(30);
	    fileCompositeSpecification pattern2=new fileSizeLessEqual(90);
	    pattern1=(fileCompositeSpecification) pattern1.and(pattern2);
	    
	    FindTool unixFind=new FindTool();
	    List<File> result=unixFind.find("/", pattern1);
	    for(File file:result) {
	    	System.out.println(file.name+"."+file.format);
	    }
	}
}
