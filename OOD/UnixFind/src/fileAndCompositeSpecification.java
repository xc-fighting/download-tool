
public class fileAndCompositeSpecification extends fileCompositeSpecification{
       IfileSpecification left;
       IfileSpecification right;
       public fileAndCompositeSpecification(IfileSpecification l,IfileSpecification r) {
    	   this.left=l;
    	   this.right=r;
       }
       
       @Override
       public boolean isSatisfiledBy(File f) {
		    
    	   return left.isSatisfiledBy(f) && right.isSatisfiledBy(f);
    	   
       }
}
