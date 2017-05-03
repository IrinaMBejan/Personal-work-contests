using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data.Linq;
using System.Data.Linq.Mapping;

namespace Calatorie.Infrastructure
{
    public static class DatabaseFactory
    {
        private static DataContext db;

        public static DataContext GetContext()
        {
            if (db == null)
                db = new CalatorieContext(Properties.Settings.Default.DBTimpSpatiuConnectionString1);
            return db;
        }
    }
}
