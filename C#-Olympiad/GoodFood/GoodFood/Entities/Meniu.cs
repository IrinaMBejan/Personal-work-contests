using System.Data.Linq.Mapping;

namespace GoodFood.Entities
{
    [Table(Name = "Meniu")]
    public class Meniu
    {
        [Column(IsPrimaryKey = true,IsDbGenerated = true)] public int id_produs { get; set; }
        [Column] public string denumire_produs { get; set; }
        [Column] public string descriere { get; set; }
        [Column] public int pret { get; set; }
        [Column] public int kcal { get; set; }
        [Column] public int felul { get; set; }
    }
}
