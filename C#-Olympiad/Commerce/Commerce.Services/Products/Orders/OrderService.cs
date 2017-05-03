using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Commerce.Data.Entities;
using Commerce.Data.Infrastructure;

namespace Commerce.Services.Orders
{
    public class OrderService : IOrderService
    {
        public IRepository<Order> orderRepository { get; set; }
        public IRepository<Product> productRepository { get; set; }
        public IRepository<OrderProduct> orderProductRepository { get; set; }
        public IUnitOfWork uow { get; set; }

        public OrderService(IUnitOfWork uow, IRepository<Order> orderRepository , IRepository<Product> productRepository, IRepository<OrderProduct> orderProductRepository)
        {
            this.orderRepository = orderRepository;
            this.productRepository = productRepository;
            this.orderProductRepository = orderProductRepository;
            this.uow = uow;
        }


        public int CreateOrder(Order order)
        {
            orderRepository.Add(order);
            uow.Commit();

            return order.OrderId;
        }

        public void AddProductToOrder(int orderId, Product product, int quantity)
        {
            var orderProduct = new OrderProduct();
            orderProduct.OrderId = orderId;
            orderProduct.Product = product;
            orderProduct.Quantity = quantity;

            orderProductRepository.Add(orderProduct);
            uow.Commit();
        }

     
    }
}
