using Commerce.Data.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Commerce.Services.Orders
{
    public interface IOrderService
    {
        int CreateOrder(Order order);
        void AddProductToOrder(int orderId, Product product, int quantity);


        //TODO
        //void AddProductsToOrder(Order order, List<Product> products); // quantity should be calculated from the list or set = 1;
        //void UpdateOrderTotal(int orderId);
        //string DisplayOrder(int orderId); // order + list of products
        //List<Order> GetOrdersByProduct(int productId); // get all the orders that have a certain product
        //void UpdateOrder(Order order);

    }
}
