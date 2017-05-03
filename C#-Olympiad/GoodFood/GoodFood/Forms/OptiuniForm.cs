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
    public partial class OptiuniForm : Form
    {
        public Client clientLogat;
        public List<Subcomanda> subcomenzi;
        public Comanda comandax;

        public OptiuniForm()
        {
            InitializeComponent();
        }

        private void CalculateButton_Click(object sender, EventArgs e)
        {
            var calc = Int32.Parse(campGreutate.Text) + Int32.Parse(campInaltime.Text)
                + Int32.Parse(campVarsta.Text);

            int kcal = 0;
            if (calc < 250)
                kcal = 1800;
            else if (calc < 275)
                kcal = 2200;
            else kcal = 2500;

            campCalorii.Text = kcal.ToString();
            campNecesarZilnic.Text = kcal.ToString();
            campCaloriiNecesare.Text = kcal.ToString();
            clientLogat.kcal_zilnice = kcal;
            RepositoryController.ClientRepository.SubmitChanges();
        }

        private void OptiuniForm_Load(object sender, EventArgs e)
        {
            tabControl1.TabPages[3].Click += OptiuniForm_Click;
            DataGridViewButtonColumn col = new DataGridViewButtonColumn();
            col.Name = "Adauga";
            col.Text = "Adauga";
            col.UseColumnTextForButtonValue = true;
            campCaloriiNecesare.Text = clientLogat.kcal_zilnice.ToString();

            dataGridView1.Columns.Add(col);
            this.meniuTableAdapter.Fill(this.gOOD_FOODDataSet.Meniu);
            campCalorii.Text = clientLogat.kcal_zilnice.ToString();
            campNecesarZilnic.Text = clientLogat.kcal_zilnice.ToString();
            campPretTotal.Text = campKcalTotal.Text = "0";

            chart1.Series.Clear();
            chart1.Series.Add("Kcal");
            chart1.Visible = true;
            chart1.Series["Kcal"].ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Column;
            

        }

        private void OptiuniForm_Click(object sender, EventArgs e)
        {
            
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.ColumnIndex == dataGridView1.Columns["Adauga"].Index)
            {
                int pret = Int32.Parse(dataGridView1.Rows[e.RowIndex].Cells[3].Value.ToString());
                int cant;
                if (dataGridView1.Rows[e.RowIndex].Cells[6].Value == null)
                    cant = 1;
                else
                    cant = Int32.Parse(dataGridView1.Rows[e.RowIndex].Cells[6].Value.ToString());
                int kcal = Int32.Parse(dataGridView1.Rows[e.RowIndex].Cells[4].Value.ToString());
                int id_produs = Int32.Parse(dataGridView1.Rows[e.RowIndex].Cells[0].Value.ToString());

                if (cant < 0)
                {
                    MessageBox.Show("Cantitate negativa", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                else
                {
                    var denumire = dataGridView1.Rows[e.RowIndex].Cells[1].Value.ToString();

                    chart1.Series["Kcal"].Points.AddXY(denumire, kcal);
                    campKcalTotal.Text = (Int32.Parse(campKcalTotal.Text) + cant*kcal).ToString();
                    campPretTotal.Text = (Int32.Parse(campPretTotal.Text) + cant*pret).ToString();

                    if (comandax == null)
                    {
                        comandax = new Comanda {id_comanda = (DateTime.Now.ToBinary().ToString()), id_client = clientLogat.id_client, data_comanda = DateTime.Now };
                    }
                    if (subcomenzi == null)
                    {
                        subcomenzi = new List<Subcomanda>();
                    }
                    subcomenzi.Add(new Subcomanda { id_comanda = comandax.id_comanda, id_produs = id_produs, cantitate = cant });
                }
            }
        }

        private void comandButton_Click(object sender, EventArgs e)
        {
            var form = new ViewCommandForm();
            form.pretTotal = campPretTotal.Text;
            form.kcalTotal = campKcalTotal.Text;
            form.necesarZilnic = campNecesarZilnic.Text;
            form.comanda = comandax;
            form.subcomenzi = subcomenzi;

            form.BringToFront();
            form.Show();
            this.Close();
        }

        private void chart1_Click(object sender, EventArgs e)
        {

        }

        private void Generator_Click(object sender, EventArgs e)
        {
            int bug = Int32.Parse(buget.Text);

            var fel1 = new DataGridViewTextBoxColumn();
            fel1.HeaderText = "Felul 1";
            fel1.Name = "fel1";

            var fel2 = new DataGridViewTextBoxColumn();
            fel2.HeaderText = "Felul 2";
            fel2.Name = "fel2";

            var fel3 = new DataGridViewTextBoxColumn();
            fel3.HeaderText = "Felul 3";
            fel3.Name = "fel3";

            var totalKcal = new DataGridViewTextBoxColumn();
            totalKcal.HeaderText = "Total kcal";
            totalKcal.Name = "totalKcal";

            var totalPret = new DataGridViewTextBoxColumn();
            totalPret.HeaderText = "Total pret";
            totalPret.Name = "totalPret";

            var alege = new DataGridViewButtonColumn();
            alege.Name = "alege";
            alege.HeaderText = "Alege";
            alege.Text = "Alege";
            alege.UseColumnTextForButtonValue = true;

            dataGridView2.Columns.Add(fel1);
            dataGridView2.Columns.Add(fel2);
            dataGridView2.Columns.Add(fel3);
            dataGridView2.Columns.Add(totalKcal);
            dataGridView2.Columns.Add(totalPret);

            var menuFel1 = RepositoryController.MeniuRepository.Query().Where(x => x.felul == 1).ToList();
            var menuFel2 = RepositoryController.MeniuRepository.Query().Where(x => x.felul == 2).ToList();
            var menuFel3 = RepositoryController.MeniuRepository.Query().Where(x => x.felul == 3).ToList();

            foreach(var felul1 in menuFel1)
                foreach(var felul2 in menuFel2)
                    foreach(var felul3 in menuFel3)
                    {
                        if(felul1.pret + felul2.pret + felul3.pret <= bug)
                        {
                            dataGridView2.Rows.Add(felul1.denumire_produs, felul2.denumire_produs, felul3.denumire_produs, felul1.kcal + felul2.kcal + felul3.kcal, felul1.pret + felul2.pret + felul3.pret);
                        }
                        felmenu1 = felul1;
                        felmenu2 = felul2;
                        felmnu3 = felul3;
                    }
            dataGridView2.Columns.Add(alege);
            dataGridView2.CellContentClick += DataGridView2_CellContentClick;
        }

        Meniu felmenu1, felmenu2, felmnu3;
        private void DataGridView2_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            if(e.ColumnIndex == dataGridView2.Columns["alege"].Index)
            {
                var comanda = new Comanda { id_comanda = (DateTime.Now.ToBinary().ToString()), id_client = clientLogat.id_client, data_comanda = DateTime.Now };
                RepositoryController.ComandaRepository.Insert(comanda);
                RepositoryController.SubcomandaRepository.Insert(new Subcomanda { id_comanda = comanda.id_comanda, id_produs = felmenu1.id_produs, cantitate = 1 });
                RepositoryController.SubcomandaRepository.Insert(new Subcomanda { id_comanda = comanda.id_comanda, id_produs = felmenu2.id_produs, cantitate = 1 });
                RepositoryController.SubcomandaRepository.Insert(new Subcomanda { id_comanda = comanda.id_comanda, id_produs = felmnu3.id_produs, cantitate = 1 });

            }
            MessageBox.Show("Comanda trimisa!", "Info", MessageBoxButtons.OK, MessageBoxIcon.Information);
            this.Close();
        }
    }
}
