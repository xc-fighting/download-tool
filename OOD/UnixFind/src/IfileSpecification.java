
public interface IfileSpecification {
   public boolean isSatisfiledBy(File f);
   public IfileSpecification and(IfileSpecification other);
   public IfileSpecification or(IfileSpecification other);
   public IfileSpecification not();

}
