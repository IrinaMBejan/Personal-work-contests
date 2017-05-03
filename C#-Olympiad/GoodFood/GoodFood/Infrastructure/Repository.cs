using System.Data.Common;
using System.Linq;
using System.Data.Linq;

namespace GoodFood.Infrastructure
{
    public class Repository<T> : IRepository<T> where T : class
    {
        private readonly DataContext db;
        private readonly Table<T> tb;
        public Repository(DataContext context)
        {
            this.db = context;
            tb = db.GetTable<T>();
        }

        public DbConnection Connection()
        {
            return db.Connection;
        }

        public int Count()
        {
            return tb.Count();
        }   

        public void Delete(T entity)
        {
            tb.DeleteOnSubmit(entity);
        }

        public void Insert(T entity)
        {
            tb.InsertOnSubmit(entity);
        }

        public IQueryable<T> Query()
        {
            return tb.AsQueryable();
        }

        public void SubmitChanges()
        {
             db.SubmitChanges();
        }
        
    }
}
