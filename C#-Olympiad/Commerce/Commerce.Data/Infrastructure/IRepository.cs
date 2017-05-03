using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;

namespace Commerce.Data.Infrastructure
{
    public interface IRepository<T> where T : class
    {
        void Add(T entity);

        int Count();

        List<T> Get(Expression<Func<T, bool>> where, string includeProperty = "");

        IQueryable<T> Query();

        void Delete(T entity);

        void Update(T entity);

     
    }
}
