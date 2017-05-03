using System;
using System.Collections.Generic;

namespace Commerce.Data.Entities
{
    public class Product
    {
        public int ProductId { get; set; }

        public string Name { get; set; }

        public string Description { get; set; }

        public int GroupId { get; set; }

        public decimal? Price { get; set; }

        public Group Group { get; set; }
        public List<OrderProduct> OrderProducts { get; set; }
    }
}
