using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data.Linq;

namespace Calatorie.Infrastructure
{
    public interface IRepository<T> where T:class
    {
        void Delete(T entity);
        void DeleteMany(IEnumerable<T> entities);
        void InsertMany(IEnumerable<T> entities);
        void Insert(T entity);
        IQueryable<T> Query();
        int Count();
        void SubmitChanges();
    }
}
