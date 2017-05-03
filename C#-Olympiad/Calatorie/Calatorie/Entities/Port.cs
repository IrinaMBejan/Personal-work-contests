using System.Data.Linq;
using System.Data.Linq.Mapping;

namespace Calatorie.Entities
{
    [Table(Name = "Porturi")]
    public class Port
    {
        [Column(IsPrimaryKey = true, IsDbGenerated = true)]
        public int ID_Port { get; set; }

        [Column]
        public string Nume_port { get; set; }

        [Column]
        public int Pozitie_X { get; set; }

        [Column]
        public int Pozitie_Y { get; set; }
    }
}
