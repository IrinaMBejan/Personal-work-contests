using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using GoodFood.Forms;
using GoodFood.Infrastructure;
using GoodFood.Entities;
namespace GoodFood
{
    public partial class StartForm : Form
    {
        public StartForm()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            pictureBox1.Image = Properties.Resources.Restaurant;
            pictureBox1.SizeMode = PictureBoxSizeMode.StretchImage;
            var elem = RepositoryController.MeniuRepository.Query().ToList();
            foreach(var eeee in elem)
            {
                RepositoryController.MeniuRepository.Delete(eeee);
            }
            
            var text = Properties.Resources.meniu;
            var lines = text.Split('\n');
            foreach(var l in lines)
            {
                var values = l.Split(';');
                if (values[0] != "id_produs" && values[0] != "" && values[0] != "\r")
                {
                    RepositoryController.MeniuRepository.Insert(new Meniu { denumire_produs = values[1].ToString(), descriere = values[2].ToString(), pret = Int32.Parse(values[3]), kcal = Int32.Parse(values[4]), felul = Int32.Parse(values[5]) });
                }
            }
            RepositoryController.MeniuRepository.SubmitChanges();
            this.FormClosing += StartForm_FormClosing;
        }

        private void StartForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            Application.Exit();
        }

        private void Inregistrare_Click(object sender, EventArgs e)
        {

            var form2 = new RegisterForm();
            form2.BringToFront();
            form2.Show();

        }

        private void Logare_Click(object sender, EventArgs e)
        {
            var form3 = new LoggingForm();
            form3.BringToFront();
            form3.Show();
        }
    }
}
