
public class fileNotCompositeSpecification extends fileCompositeSpecification{
     IfileSpecification single;
     public fileNotCompositeSpecification(IfileSpecification s) {
    	  this.single=s;
     }
     
     @Override
     public boolean isSatisfiledBy(File f) {
    	 return !single.isSatisfiledBy(f);
     }
}
