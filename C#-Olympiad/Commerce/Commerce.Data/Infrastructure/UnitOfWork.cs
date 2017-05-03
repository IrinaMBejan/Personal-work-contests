using Microsoft.EntityFrameworkCore;

namespace Commerce.Data.Infrastructure
{
  public class UnitOfWork : IUnitOfWork
  {
    private readonly IDatabaseFactory databaseFactory;
    private DbContext dataContext;

    public UnitOfWork(IDatabaseFactory databaseFactory)
    {
      this.databaseFactory = databaseFactory;
    }

    protected DbContext DataContext
    {
      get { return dataContext ?? (dataContext = databaseFactory.Get()); }
    }

    public void Commit()
    {
      //commit to database
      DataContext.SaveChanges();
    }

  }

}
