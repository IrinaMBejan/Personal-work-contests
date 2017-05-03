using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Commerce.Data.Entities;

namespace Commerce.Services.Products
{
    public interface IProductsService
    {
        List<Product> GetProductsByName(string productName = "");
        List<Product> GetProductsByGroupName(string groupName = "");
        List<Product> GetTopMostExpensiveProducts(int nrOfProducts);
        List<Product> GetTopMostExpensiveProducts(int nrOfProducts, decimal startingPrice);

        List<Group> GetGroups();
        void Update(Product product);
    }
}
