import java.util.ArrayList;
import java.util.List;

public class File {
   public boolean isDir;
   //size of file
   public int size;
   //the name
   public String name;
   //jpeg,txt,png
   public String format;
   public List<File> children;
   public File(boolean dir,int size,String name,String format) {
	   this.isDir=dir;
	   this.size=size;
	   this.name=name;
	   this.format=format;
	   children=new ArrayList<File>();
   }
   
   
}
