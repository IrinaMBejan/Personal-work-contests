using System.IO;
using Commerce.Data.Entities;
using Microsoft.EntityFrameworkCore;

namespace Commerce.Data.Infrastructure
{
    public class CommerceContext : DbContext
    {
        public DbSet<Product> Products { get; set; }
        public DbSet<Group> Groups { get; set; }
        public DbSet<Order> Orders { get; set; }
        public DbSet<OrderProduct> OrderProducts { get; set; }

        protected override void OnConfiguring(DbContextOptionsBuilder builder)
        {
            var currentFolder = Directory.GetCurrentDirectory();
            var dbFile = "Commerce.mdf";
            var dbFullPath = Path.Combine(currentFolder, dbFile);

            builder.UseSqlServer($@"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename={dbFullPath};Integrated Security=True;Connect Timeout=30");
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Product>().ToTable("Products");
            modelBuilder.Entity<Group>().ToTable("Groups");
            modelBuilder.Entity<Order>().ToTable("Orders");
            modelBuilder.Entity<OrderProduct>().ToTable("OrderProducts").HasKey(x => new { x.ProductId, x.OrderId });
        }
    }
}
