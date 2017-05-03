using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using GoodFood.Entities;
using GoodFood.Infrastructure;

namespace GoodFood.Forms
{
    public partial class ViewCommandForm : Form
    {
        public string kcalTotal;
        public string pretTotal;
        public string necesarZilnic;

        public Comanda comanda;
        public List<Subcomanda> subcomenzi;

        public ViewCommandForm()
        {
            InitializeComponent();
        }

        private void ViewCommandForm_Load(object sender, EventArgs e)
        {
            campKcalTotal.Text = kcalTotal;
            campNecesarZilnic.Text = necesarZilnic;
            campPretTotal.Text = pretTotal;
            
            var numeColumn = new DataGridViewTextBoxColumn();
            numeColumn.DataPropertyName = "Nume produs";
            numeColumn.Name = "Nume produs";
            numeColumn.HeaderText = "Nume produs";

            var idprodus = new DataGridViewTextBoxColumn();
            idprodus.DataPropertyName = "idprodus";
            idprodus.Name = "idprodus";
            idprodus.HeaderText = "idprodus";
            idprodus.Visible = false;

            var kcalColumn = new DataGridViewTextBoxColumn();
            kcalColumn.DataPropertyName = "kcal";
            kcalColumn.Name = "kcal";
            kcalColumn.HeaderText = "kcal";

            var pretColumn = new DataGridViewTextBoxColumn();
            pretColumn.DataPropertyName = "pret";
            pretColumn.Name = "pret";
            pretColumn.HeaderText = "pret";

            var cantColumn = new DataGridViewTextBoxColumn();
            cantColumn.DataPropertyName = "cantitate";
            cantColumn.Name = "cantitate";
            cantColumn.HeaderText = "cantitate";

            dataGridView1.Columns.Add(idprodus);
            dataGridView1.Columns.Add(numeColumn);
            dataGridView1.Columns.Add(kcalColumn);
            dataGridView1.Columns.Add(pretColumn);
            dataGridView1.Columns.Add(cantColumn);

            var row = new DataGridViewRow();
            foreach(var sub in subcomenzi)
            {
                var prod = RepositoryController.MeniuRepository.Query().Where(x => x.id_produs == sub.id_produs).FirstOrDefault();
                dataGridView1.Rows.Add(prod.id_produs,prod.denumire_produs, prod.kcal, prod.pret, sub.cantitate);
            }

            var elimColumn = new DataGridViewButtonColumn();
            elimColumn.Name = "Elimina";
            elimColumn.Text = "Elimina";
            elimColumn.HeaderText = "Elimina";
            elimColumn.UseColumnTextForButtonValue = true;

            dataGridView1.Columns.Add(elimColumn);
            dataGridView1.CellContentClick += DataGridView1_CellContentClick;
            

        }

        private void DataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
             if(e.ColumnIndex == dataGridView1.Columns["Elimina"].Index)
            {
                var kcal = Int32.Parse(dataGridView1.Rows[e.RowIndex].Cells["kcal"].Value.ToString());
                var pret = Int32.Parse(dataGridView1.Rows[e.RowIndex].Cells["pret"].Value.ToString());
                var cant = Int32.Parse(dataGridView1.Rows[e.RowIndex].Cells["cantitate"].Value.ToString());
                var idprodus = Int32.Parse(dataGridView1.Rows[e.RowIndex].Cells["idprodus"].Value.ToString());

                campKcalTotal.Text = (Int32.Parse(campKcalTotal.Text) - kcal * cant).ToString();
                campPretTotal.Text = (Int32.Parse(campPretTotal.Text) - pret * cant).ToString();

                Subcomanda toRemove = null;
                foreach(var sub in subcomenzi)
                {
                    if (sub.id_produs == idprodus)
                        toRemove = sub;
                }
                subcomenzi.Remove(toRemove);
                dataGridView1.Rows.Remove(dataGridView1.Rows[e.RowIndex]);

            }
        }

        private void SalveazaComanda_Click(object sender, EventArgs e)
        {
            comanda.data_comanda = DateTime.Now;
            RepositoryController.ComandaRepository.Insert(comanda);
            foreach (var sub in subcomenzi)
                RepositoryController.SubcomandaRepository.Insert(sub);
            RepositoryController.SubcomandaRepository.SubmitChanges();
            
            this.Close();
            
            
        }
    }
}
