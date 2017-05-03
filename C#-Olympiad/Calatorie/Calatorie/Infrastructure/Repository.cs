using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data.Linq;

namespace Calatorie.Infrastructure
{
    public class Repository<T> : IRepository<T> where T : class
    {
        private readonly DataContext dc;
        private readonly Table<T> tb;
        public Repository()
        {
            dc = DatabaseFactory.GetContext();
            tb = dc.GetTable<T>();
        }
        public int Count()
        {
            return tb.Count();
        }

        public void Delete(T entity)
        {
            tb.DeleteOnSubmit(entity);
        }

        public void DeleteMany(IEnumerable<T> entities)
        {
            tb.DeleteAllOnSubmit(entities);
        }

        public void Insert(T entity)
        {
            tb.InsertOnSubmit(entity);
        }

        public void InsertMany(IEnumerable<T> entities)
        {
            tb.DeleteAllOnSubmit(entities);
        }

        public IQueryable<T> Query()
        {
            return tb.AsQueryable();
        }

        public void SubmitChanges()
        {
            dc.SubmitChanges();
        }
    }
}
