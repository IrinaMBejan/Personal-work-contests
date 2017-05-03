using System.Data.Linq;
using System.Data.Linq.Mapping;

using GoodFood.Entities;

namespace GoodFood.Infrastructure
{
    [Database]
    public class FoodContext : DataContext
    {
        public Table<Client> clienti;
        public Table<Meniu> meniuri;
        public Table<Subcomanda> subcomenzi;
        public Table<Comanda> comenzi;

        public FoodContext(string connectionString)
            : base(connectionString)
        {
        }
    }
}
