using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Calatorie.Entities;
namespace Calatorie.Infrastructure
{
    public static class RepositoryController
    {
        private static Repository<Croaziera> croazieraRepo;
        private static Repository<Port> portRepo;
        private static Repository<Distant> distantRepo;

        public static Repository<Croaziera> CroazieraRepo
        {
            get
            {
                if (croazieraRepo == null)
                    croazieraRepo = new Repository<Croaziera>();
                return croazieraRepo;
            }
        }

        public static Repository<Port> PortRepo
        {
            get
            {
                if (portRepo == null)
                    portRepo = new Repository<Port>();
                return portRepo;
            }
        }

        public static Repository<Distant> DistantRepo
        {
            get
            {
                if (distantRepo == null)
                    distantRepo = new Repository<Distant>();
                return distantRepo;
            }
        }
    }
}
