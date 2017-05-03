using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using Calatorie.Infrastructure;
using Calatorie.Entities;
using Calatorie.Forms;

namespace Calatorie
{
    public partial class Autentificare : Form
    {
        public string tip;
        public Autentificare()
        {
            InitializeComponent();
        }

        private void Autentificare_Load(object sender, EventArgs e)
        {
            

        }

        private void Auten_Click(object sender, EventArgs e)
        {
            tip = "";
            if(campUser.Text == "Administrator" && campParola.Text == "agentie2015")
            {
                tip = "admin";
                
            }
            else if(campUser.Text == "Turist" && campParola.Text == "oti2015")
            {
                tip = "client";
            }
            if(tip != "")
            {
                var mdiContainer = new MDI();
                mdiContainer.tip = tip;
                mdiContainer.BringToFront();
                mdiContainer.Show();
                this.Hide();
            }
            else
            {
                MessageBox.Show("Datele introduse nu sunt valide, reincercati !", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
