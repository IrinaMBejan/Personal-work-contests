using System;
using System.Collections.Generic;
using System.Linq;
using System
    ;
using System.Threading.Tasks;

using GoodFood.Entities;
namespace GoodFood.Infrastructure
{
    public static class RepositoryController
    {
        private static Repository<Client> clientRepository;
        private static Repository<Meniu> meniuRepository;
        private static Repository<Subcomanda> subcomandaRepository;
        private static Repository<Comanda> comandaRepository;

        public static Repository<Client> ClientRepository
        {
            get
            {
                if (clientRepository == null)
                {
                    var dc = DatabaseFactory.GetContext();
                    clientRepository = new Repository<Client>(dc);
                }
                return clientRepository;
            }
        }

        public static Repository<Meniu> MeniuRepository
        {
            get
            {
                if (meniuRepository == null)
                {
                    var dc = DatabaseFactory.GetContext();
                    meniuRepository = new Repository<Meniu>(dc);
                }
                return meniuRepository;
            }
        }

        public static Repository<Comanda> ComandaRepository
        {
            get
            {
                if (comandaRepository == null)
                {
                    var dc = DatabaseFactory.GetContext();
                    comandaRepository = new Repository<Comanda>(dc);
                }
                return comandaRepository;
            }
        }

        public static Repository<Subcomanda> SubcomandaRepository
        {
            get
            {
                if (subcomandaRepository == null)
                {
                    var dc = DatabaseFactory.GetContext();
                    subcomandaRepository = new Repository<Subcomanda>(dc);
                }
                return subcomandaRepository;
            }
        }
    }
}
