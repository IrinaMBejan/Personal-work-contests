using Microsoft.AspNetCore.Mvc.Rendering;
using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Threading.Tasks;

namespace Commerce.Web.ViewModels.Products
{
    public class ProductEdit
    {
        public int ProductId { get; set; }
        [Required]
        public string Name { get; set; }
        [Required]
        public string Description { get; set; }
        [Required]
        public int GroupId { get; set; }

        public decimal? Price { get; set; }    
        
        public SelectList GroupList { get; set; }
          
    }
}
