using System;
using System.Windows.Forms;
using System.ComponentModel.DataAnnotations;
using System.Linq;

using GoodFood.Infrastructure;
using GoodFood.Entities;

namespace GoodFood
{
    public partial class RegisterForm : Form
    {
        public RegisterForm()
        {
            InitializeComponent();
        }

        private void RegisterForm_Load(object sender, EventArgs e)
        {
            pictureBox1.Image = Properties.Resources.Restaurant;
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
        }

        private bool IsDataValid()
        {
            if (campAdresa.Text == "" || campEmail.Text == "" || campNume.Text == ""
                || campParola.Text == "" || campParolaNou.Text == "" || campPrenume.Text == "")
            {
                MessageBox.Show("Toate campurile trebuie completate!", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }

            var checker = new EmailAddressAttribute();
            if(checker.IsValid(campEmail.Text) == false)
            {
                MessageBox.Show("Adresa de email nu a putut fi validata!", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
                campEmail.Text = "";
                return false;
            }

            if(campParola.Text != campParolaNou.Text)
            {
                MessageBox.Show("Parolele nu corespund, reincercati !", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
                campParola.Text = "";
                campParolaNou.Text = "";
            }

            return true;
        }

        private void creareCont_Click(object sender, EventArgs e)
        {
            if (IsDataValid())
            {
                var nrClient = RepositoryController.ClientRepository.Query().Where(x => x.email == campEmail.Text.ToString()).Count();
                if(nrClient != 0)
                {
                    MessageBox.Show("Deja exista un client cu acest email !", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    campEmail.Text = "";
                    return;
                }

                RepositoryController.ClientRepository.Insert(new Client { nume = campNume.Text.ToString(), prenume = campPrenume.Text.ToString(), adresa = campAdresa.Text.ToString(), email = campEmail.Text.ToString(), parola = campParola.Text.ToString() });
                RepositoryController.ClientRepository.SubmitChanges();
                this.Hide();
            }
        }
    }
}
