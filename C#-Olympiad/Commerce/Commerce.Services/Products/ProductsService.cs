using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Commerce.Data.Entities;
using Commerce.Data.Infrastructure;
using Microsoft.EntityFrameworkCore;

namespace Commerce.Services.Products
{
    public class ProductsService : IProductsService
    {
        private readonly IRepository<Product> productRepository;
        private readonly IRepository<OrderProduct> orderProductRepository;
        private readonly IUnitOfWork unitOfWork;
        private readonly IRepository<Group> groupRepository;

        public ProductsService(IRepository<Product> productRepository, IUnitOfWork unitOfWork, IRepository<OrderProduct> orderProductRepository, IRepository<Group> groupRepository)
        {
            this.productRepository = productRepository;
            this.unitOfWork = unitOfWork;
            this.orderProductRepository = orderProductRepository;
            this.groupRepository = groupRepository;
        }
        public List<Group> GetGroups()
        {
            return groupRepository.Get(g => true).ToList();

        }

        public void Update(Product product)
        {
            productRepository.Update(product);
            unitOfWork.Commit();
        }

        public List<Product> GetProductsByGroupName(string groupName="")
        {

            var products = productRepository.Query().Include(p => p.Group).Where(p => p.Group.Name.Contains(groupName)).ToList();

            return products;
        }

        public List<Product> GetProductsByName(string productName="")
        {
            var products = (from p in productRepository.Query().Include("Group")
                            where p.Name.Contains(productName)
                            select p).ToList();

            var lambdaProducts = productRepository.Query()
                                                  .Where(p => p.Name.Contains(productName))
                                                  .ToList();
            return products;
        }

        public List<Product> GetTopMostExpensiveProducts(int nrOfProducts)
        {
            //linq
            var products = (from p in productRepository.Query()
                            orderby p.Price descending
                            select p).Take(nrOfProducts).ToList();

            //expresii lambda   
            var lambdaProducts = productRepository.Query()
                                                  .OrderByDescending(p => p.Price)
                                                  .Take(nrOfProducts).ToList();
            return lambdaProducts;
        }

        public List<Product> GetTopMostExpensiveProducts(int nrOfProducts, decimal startingPrice)
        {
            //linq
            var products = (from p in productRepository.Query()
                            where p.Price > startingPrice
                            orderby p.Price descending
                            select p).Take(nrOfProducts).ToList();

            //expresii lambda   
            var lambdaProducts = productRepository.Query()
                                                  .Where(p => p.Price > startingPrice)
                                                  .OrderByDescending(p => p.Price)
                                                  .Take(nrOfProducts).ToList();
            return lambdaProducts;
        }
    }
}
