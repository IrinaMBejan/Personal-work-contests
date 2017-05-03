using System.Data.Linq.Mapping;

namespace GoodFood.Entities
{
    [Table(Name = "Subcomenzi")]
    public class Subcomanda
    {
        [Column(IsPrimaryKey = true, IsDbGenerated = true)] public int id_subcomanda { get; set; }
        [Column] public string id_comanda { get; set; }
        [Column] public int id_produs { get; set; }
        [Column] public int cantitate { get; set; }
    }
}
