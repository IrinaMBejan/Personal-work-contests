using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Commerce.Data.Entities;
using Commerce.Data.Infrastructure;
using Commerce.Services.Infrastructure;
using Commerce.Services.Products;
using SimpleInjector;
using Commerce.Services.Orders;

namespace Commerce.Console
{
    public class Program
    {
        static Container container;

        static Program()
        {
            container = new Container();
            var lifeStyle = Lifestyle.Singleton;

            container.Register<IDatabaseFactory, DatabaseFactory>(lifeStyle);
            container.Register<IUnitOfWork, UnitOfWork>(lifeStyle);
            container.Register(typeof(IRepository<>), typeof(Repository<>), lifeStyle);
            container.Register(typeof(IBaseService<>), typeof(BaseService<>), lifeStyle);


            container.Register<IProductsService, ProductsService>(lifeStyle);
            container.Register<IOrderService, OrderService>(lifeStyle);
            container.Verify();
        }

        public static void Main(string[] args)
        {

            var productService = container.GetInstance<IProductsService>();
            var searchedProducts = productService.GetProductsByName("keyboard");



            foreach (var product in searchedProducts)
            {
                System.Console.WriteLine(product.Name);
            }

            System.Console.WriteLine("Top products :");
            var topProducts = productService.GetTopMostExpensiveProducts(3);

            foreach (var product in topProducts)
            {
                System.Console.WriteLine(product.Name + " : " + product.Price.ToString());
            }

           // System.Console.ReadLine();



            var orderService = container.GetInstance<IOrderService>();
            var order = new Order();
            order.ClientName = "dorel";
            order.Address = "iasi nr 10";
            order.OrderDate = DateTime.Now;
            order.ShipmentDate = DateTime.Now.AddDays(3);
            order.Total = 0;

            var orderId = orderService.CreateOrder(order);

            foreach (var product in topProducts)
            {
                orderService.AddProductToOrder(orderId, product, 1);
            }

        }
    }
}
