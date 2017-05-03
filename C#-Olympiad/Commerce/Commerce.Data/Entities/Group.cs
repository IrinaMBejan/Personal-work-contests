using System.Collections.Generic;

namespace Commerce.Data.Entities
{
  public class Group
  {
    public int GroupId { get; set; }

    public string Name { get; set; }

    public List<Product> Products { get; set; }
  }
}
