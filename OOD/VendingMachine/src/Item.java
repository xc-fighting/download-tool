
public class Item {
   public double price;
   public String name;
   public ItemCategory category;
   public int remains;
   
   public Item(double p,String n,ItemCategory cat,int remain)
   {
	   this.price=p;
	   this.name=n;
	   this.category=cat;
	   this.remains=remain;
   }
   
   public String toString()
   {
	   StringBuilder builder = new StringBuilder();
	   builder.append("the name is:");
	   builder.append(name);
	   builder.append("\n");
	   builder.append("the price is:");
	   builder.append(price);
	   builder.append("\n");
	   builder.append("the category is:");
	   builder.append(category.toString());
	   builder.append("\n");
	   builder.append("the remaining:");
	   builder.append(remains);
	   builder.append("\n");
	   return builder.toString();
   }
}
