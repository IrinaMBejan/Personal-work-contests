using System.Data.Linq;

namespace GoodFood.Infrastructure
{
    public static class DatabaseFactory
    {
        private static DataContext dc;

        public static DataContext GetContext()
        {
            if (dc == null)
                dc = new FoodContext(Properties.Settings.Default.GoodFoodConnectionString);
            return dc;
        
        }
    }
}
