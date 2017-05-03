using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;

namespace Commerce.Web.Controllers
{
    public class TestController : Controller
    {
        public IActionResult Index()
        {
            return View();
        }

        public IActionResult GetDate()
        {
            var viewModel = DateTime.Now.ToString();
            return View("GetDate", viewModel);
        }
    }
}