using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using Microsoft.EntityFrameworkCore;

namespace Commerce.Data.Infrastructure
{
    public class Repository<T> : IRepository<T> where T : class
    {

        private DbContext dataContext;
        private readonly DbSet<T> dbset;

        public Repository(IDatabaseFactory databaseFactory)
        {
            DatabaseFactory = databaseFactory;
            dbset = DataContext.Set<T>();
        }

        protected IDatabaseFactory DatabaseFactory { get; private set; }

        protected DbContext DataContext
        {
            get { return dataContext ?? (dataContext = DatabaseFactory.Get()); }
        }

        public virtual void Add(T entity)
        {
            dbset.Add(entity);
        }

        public virtual int Count()
        {
            return dbset.Count();
        }

        public List<T> Get(Expression<Func<T, bool>> where, string includeProperty = "")
        {
            var query = dbset.Where(where);

            if (!string.IsNullOrEmpty(includeProperty))
            {
                query = query.Include(includeProperty);
            }

            return query.ToList();
        }

        public void Delete(T entity)
        {
            dbset.Remove(entity);
        }

        public void Update(T entity)
        {
            dbset.Attach(entity);
            dataContext.Entry(entity).State = EntityState.Modified;
        }

        public IQueryable<T> Query()
        {
            return dbset.AsQueryable();
        }
    }
}
