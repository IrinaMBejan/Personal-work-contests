using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data.Linq;
using System.Data.Linq.Mapping;

namespace Calatorie.Entities
{
    [Table(Name = "Croaziera")]
    public class Croaziera
    {
        [Column(IsPrimaryKey = true, IsDbGenerated = true)]
        public int ID_Croaziera { get; set; }

        [Column]
        public int Tip_Croaziera { get; set; }

        [Column]
        public string Lista_Porturi { get; set; }

        [Column]
        public DateTime Data_Start { get; set; }

        [Column]
        public DateTime Data_Final { get; set; }

        [Column]
        public int Pret { get; set; }

        [Column]
        public int Nr_Pasageri { get; set; }
    }
}
