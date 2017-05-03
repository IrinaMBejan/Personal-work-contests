using System;
using System.Collections.Generic;

namespace Commerce.Data.Entities
{
    public class Order
    {
        public int OrderId { get; set; }

        public decimal Total { get; set; }

        public DateTime OrderDate { get; set; }

        public DateTime ShipmentDate { get; set; }

        public string ClientName { get; set; }

        public string Address { get; set; }

        public List<OrderProduct> OrderProducts { get; set; }
    }
}
