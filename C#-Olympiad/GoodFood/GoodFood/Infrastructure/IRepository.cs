using System.Linq;

using System.Data.Common;
namespace GoodFood.Infrastructure
{
    public interface IRepository<T> where T: class
    {
        void Delete(T entity);
        void Insert(T entity);
        void SubmitChanges();

        IQueryable<T> Query();
        DbConnection Connection();
        int Count();
    }
}
