using System.Data.Linq.Mapping;

namespace Calatorie.Entities
{
    [Table(Name = "Distante")]
    public class Distant
    {
        [Column(IsPrimaryKey = true)]
        public int ID_Port { get; set; }

        [Column(IsPrimaryKey = true)]
        public int ID_Port_Destinatie { get; set; }

        [Column]
        public string Nume_Port_Destinatie { get; set; }

        [Column]
        public int Distanta { get; set; }
    }
}
