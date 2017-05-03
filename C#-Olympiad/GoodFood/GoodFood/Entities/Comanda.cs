using System;
using System.Data.Linq.Mapping;

namespace GoodFood.Entities
{
    [Table(Name = "Comenzi")]
    public class Comanda
    {
        [Column(IsPrimaryKey = true)] public string id_comanda { get; set; }
        [Column] public int id_client { get; set; }
        [Column] public DateTime data_comanda { get; set; }
    }
}
