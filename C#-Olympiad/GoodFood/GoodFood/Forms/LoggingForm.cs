using System;
using System.Windows.Forms;
using System.Linq;
using System.Collections.Generic;
using GoodFood.Infrastructure;

namespace GoodFood.Forms
{
    public partial class LoggingForm : Form
    {
        public LoggingForm()
        {
            InitializeComponent();
        }

        private void LoggingForm_Load(object sender, EventArgs e)
        {

        }
        
        private void Intra_Click(object sender, EventArgs e)
        {
            var clienti = RepositoryController.ClientRepository.Query().ToList();
            var client = RepositoryController.ClientRepository.Query().Where(x => x.email == campEmail.Text.ToString() && x.parola == campParola.Text.ToString()).FirstOrDefault();
            if (client == null)
            {
                MessageBox.Show("Eroare autentificare!", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                var form = new OptiuniForm();
                form.clientLogat = client;
                this.Hide();
                form.BringToFront();
                form.Show();
            }
        }
    }
}
