using System;
using System.Linq.Expressions;

namespace Commerce.Services.Infrastructure
{
  public interface IBaseService<T> where T : class
  {
    void Add(T entity);

    int Count();

    System.Collections.Generic.List<T> Get(Expression<Func<T, bool>> where, string includeProperty = "");

  }
}
