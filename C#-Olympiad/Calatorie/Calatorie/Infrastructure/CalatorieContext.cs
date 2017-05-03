using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data.Linq;
using System.Data.Linq.Mapping;

using Calatorie.Entities;
namespace Calatorie.Infrastructure
{
    [Database]
    public class CalatorieContext: DataContext
    {
        Table<Distant> distantSet;
        Table<Port> porturiSet;
        Table<Croaziera> croazieraSet;

        public CalatorieContext(string connectionString):
            base(connectionString)
        {

        }


    }
}
