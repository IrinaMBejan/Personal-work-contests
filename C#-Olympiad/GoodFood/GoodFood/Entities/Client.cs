using System.Data.Linq.Mapping;

namespace GoodFood.Entities
{
    [Table(Name = "Clienti")]
    public class Client
    {
        [Column(IsPrimaryKey = true, IsDbGenerated = true)] public int id_client { get; set; }
        [Column] public string parola { get; set; }
        [Column] public string nume { get; set; }
        [Column] public string prenume { get; set; }
        [Column] public string adresa { get; set; }
        [Column] public string email { get; set; }
        [Column] public int kcal_zilnice { get; set; }
    }
}
