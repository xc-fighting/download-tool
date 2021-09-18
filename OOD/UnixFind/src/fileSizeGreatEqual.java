
public class fileSizeGreatEqual extends fileCompositeSpecification{
     
     int sizeCompare;
     public fileSizeGreatEqual(int s) {
    	 
    	  this.sizeCompare=s;
     }
     
     @Override
     public boolean isSatisfiledBy(File f) {
    	 return f.size>=sizeCompare;
     }
}
