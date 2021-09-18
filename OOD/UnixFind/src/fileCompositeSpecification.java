
public class fileCompositeSpecification implements IfileSpecification{

	@Override
	public boolean isSatisfiledBy(File f) {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public IfileSpecification and(IfileSpecification other) {
		// TODO Auto-generated method stub
		return new fileAndCompositeSpecification(this,other); 
	}

	@Override
	public IfileSpecification or(IfileSpecification other) {
		// TODO Auto-generated method stub
		return new fileOrCompositeSpecification(this,other);
	}

	@Override
	public IfileSpecification not() {
		// TODO Auto-generated method stub
		return new fileNotCompositeSpecification(this);
	}

	

}
