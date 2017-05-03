using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Commerce.Web.ViewModels.Products;

using Commerce.Data.Entities;
using Commerce.Services.Products;
using Microsoft.AspNetCore.Mvc.Rendering;
using Omu.ValueInjecter;

// For more information on enabling MVC for empty projects, visit http://go.microsoft.com/fwlink/?LinkID=397860

namespace Commerce.Web.Controllers
{
    public class ProductsController : Controller
    {
        private readonly IProductsService productsService;
        public ProductsController(IProductsService productsService)
        {
            this.productsService = productsService;
        }
        public IActionResult Index()
        {
            var products = productsService.GetProductsByName("");

            var productGridItems = products.Select(p => new ProductGridItem() { ProductId = p.ProductId, Description = p.Description, GroupName = p.Group.Name, Name = p.Name });

            return View(productGridItems.ToList());
        }

        public IActionResult Search(SearchTerm searchTerm, string productName = "", string groupName = "")
        {
            if (string.IsNullOrEmpty(productName)) productName = string.Empty;


            var productsByproductName = productsService.GetProductsByName(productName);

            var productsByGroup = productsService.GetProductsByGroupName(groupName);

            var products = productsByproductName.Intersect(productsByGroup);

            var productGridItems = products.Select(p => new ProductGridItem() { ProductId = p.ProductId, Description = p.Description, GroupName = p.Group.Name, Name = p.Name });

            return View("Index", productGridItems.ToList());
        }

        public IActionResult Edit(int? productId)
        {
            if (!productId.HasValue)
            {
                var myProductModelView = new ProductEdit();
                myProductModelView.GroupList = new SelectList(productsService.GetGroups(), "GroupId", "Name");

                return View(myProductModelView);
            }

            var myProductEntity = productsService.GetProductsByName("").Where(p => p.ProductId == productId).FirstOrDefault();

            var groups = productsService.GetGroups();

            var myProductModel = new ProductEdit();

            myProductModel.GroupList = new SelectList(groups, "GroupId", "Name");
            myProductModel.Description = myProductEntity.Description;
            myProductModel.Price = myProductEntity.Price;
            myProductModel.Name = myProductEntity.Name;
            myProductModel.ProductId = myProductEntity.ProductId;
            myProductModel.GroupId = myProductEntity.GroupId;
            
            return View(myProductModel);
        }
        [HttpPost]
        public IActionResult Edit(ProductEdit product)
        {
            if(ModelState.IsValid)
            {
                var productEntity = new Product();

                productEntity.InjectFrom(product);
                //productEntity.Description = product.Description;
                //productEntity.Name = product.Name;
                //productEntity.GroupId = product.GroupId;
                //productEntity.Price = product.Price;
                //productEntity.ProductId = product.ProductId;
                productsService.Update(productEntity);


            }
            return View(product);
        }
    }

    public class SearchTerm
    {
        public string ProductName { get; set; }
        public string GroupName { get; set; }
    }

}
