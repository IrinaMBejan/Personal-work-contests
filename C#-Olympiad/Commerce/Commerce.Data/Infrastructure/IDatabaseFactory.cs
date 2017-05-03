using Microsoft.EntityFrameworkCore;

namespace Commerce.Data.Infrastructure
{
  public interface IDatabaseFactory
  {
    DbContext Get();
  }

}
