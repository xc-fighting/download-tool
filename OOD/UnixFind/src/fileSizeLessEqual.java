
public class fileSizeLessEqual extends fileCompositeSpecification{
	 
	 int s;
     
     
     public fileSizeLessEqual(int size) {
    	 this.s=size;
     }
     
    
     
     @Override
     public boolean isSatisfiledBy(File f) {
    	 return f.size<=s;
     }
}
