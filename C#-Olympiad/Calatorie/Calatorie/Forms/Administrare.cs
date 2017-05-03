using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Data.Linq;
using System.Data.Linq.SqlClient;
using Calatorie.Entities;
using Calatorie.Infrastructure;
using System.Windows.Input;
namespace Calatorie.Forms
{
    public partial class Administrare : Form
    {
        List<Point> points;
        Point[] initializedPoints;
        int lg;
        string[] cities = { "Constanta", "Varna", "Burgas", "Istambul", "Kozlu", "Samsun", "Batumi", "Sokhumi", "Soci", "Anapa", "Yalta", "Sevastopol", "Odessa" };

        int[,] mat;
        public Administrare()
        {
            InitializeComponent();
        }
        Point lastPoint;
        private void pictureBox1_MouseClick(object sender, MouseEventArgs e)
        {
            Point x = new Point { X = e.X, Y = e.Y};


            if (points == null)
                points = new List<Point>();
            points.Add(new Point { X = e.X, Y = e.Y });

            if (lastPoint == null)
                lastPoint = new Point { X = pictureBox1.Location.X, Y = pictureBox1.Location.Y };
            else
            {
                Bitmap bm = new Bitmap(pictureBox1.Image);
                Graphics gf = Graphics.FromImage(bm);
                Pen pen = new Pen(Color.Red);
                pen.Width = 10;


                gf.DrawLine(pen, lastPoint, x);

                gf.Dispose();

                pictureBox1.Image = bm;
            }
            lastPoint = x;
        }

        private void Intializare_Click(object sender, EventArgs e)
        {
            if (initializedPoints == null)
                initializedPoints = new Point[15];
            points.CopyTo(initializedPoints);
            lg = points.Count();

            points.Clear();
        }

        private void Salvare_Click(object sender, EventArgs e)
        {
            if(lg != 13)
            {
                MessageBox.Show("Au fost inregistrate doar " + lg.ToString() + " pozitii pentru cele 13 orase", "Eroare", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                var ports = RepositoryController.PortRepo.Query().ToList();
                RepositoryController.PortRepo.DeleteMany(ports);
                for (int i = 0; i < lg; i++)
                    RepositoryController.PortRepo.Insert(new Port { Nume_port = cities[i], Pozitie_X = initializedPoints[i].X, Pozitie_Y = initializedPoints[i].Y });
            }
        }

        private void Actualizare_Click(object sender, EventArgs e)
        {
            if (mat == null)
                mat = new int[15,15];
            var text = Properties.Resources.Harta_Distantelor;

            var lines = text.Split('\n');
            for(int i = 0; i<lines.Count(); i++)
            {
                var values = lines[i].Split(' ');
                for(int j = 0; j<values.Count(); j++)
                    mat[i,j] = Int32.Parse(values[j]);
            }
        }

        struct Croaz
        {
            public List<int> porturi;
            public int dist;
        }

        int[] porturi;
        List<Croaz> croazier;
        private void Generare_Click(object sender, EventArgs e)
        {
            if (croazier == null)
            {
                croazier = new List<Croaz>();
            }
            if (porturi == null)
            {
                porturi = new int[20];
            }
            croazier.Clear();
            
            bkt3(1, 0);
            bkt5(1, 0);
            bkt8(1, 0);

            foreach(var c in croazier)
            {
                Croaziera cro = new Croaziera();
                cro.Data_Start = DateTime.Now;
                cro.Data_Final = DateTime.Now;


                RepositoryController.CroazieraRepo.Insert(cro);
            }
        }

        private void bkt3(int k, int dist)
        {
            if (k == 4)
            {
                dist = dist + mat[0, porturi[0]] + mat[porturi[2], 0]; ;
                if (dist <= 1100 && dist >= 800)
                {
                    var crz = new Croaz();
                    crz.porturi = new List<int>();
                    crz.porturi = porturi.ToList();
                    crz.dist = dist;
                }
            }
            else
            {
                for (int j = porturi[k - 1]; j <= 13; j++)
                {
                    porturi[k] = j;
                    bkt3(k + 1, dist + mat[porturi[k - 1] - 1, porturi[k] - 1]);
                }
            }
        }
        private void bkt8(int k, int dist)
        {
            if (k == 9)
            {
                dist = dist + mat[0, porturi[0]] + mat[porturi[2], 0]; ;
                if (dist <= 1900 && dist >= 800)
                {
                    var crz = new Croaz();
                    crz.porturi = new List<int>();
                    crz.porturi = porturi.ToList();
                    crz.dist = dist;
                }
            }
            else
            {
                for (int j = porturi[k - 1]; j <= 13; j++)
                {
                    porturi[k] = j;
                    bkt8(k + 1, dist + mat[porturi[k - 1] - 1, porturi[k] - 1]);
                }
            }
        }
        private void bkt5(int k, int dist)
        {
            if (k == 6)
            {
                dist = dist + mat[0, porturi[0]] + mat[porturi[2], 0]; ;
                if (dist <= 1600 && dist >= 800)
                {
                    var crz = new Croaz();
                    crz.porturi = new List<int>();
                    crz.porturi = porturi.ToList();
                    crz.dist = dist;
                }
            }
            else
            {
                for (int j = porturi[k - 1]; j <= 13; j++)
                {
                    porturi[k] = j;
                    bkt5(k + 1, dist + mat[porturi[k - 1] - 1, porturi[k] - 1]);
                }
            }
        }

        private void Administrare_Load(object sender, EventArgs e)
        {
            pictureBox1.Image = Properties.Resources.MareaNeagra;
            pictureBox1.SizeMode = PictureBoxSizeMode.Normal;
               
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }
    }
}
/*
Distanta minima 800 km
Distanta maxima:
- 3 zile 1100
- 5 zile 1600
- 8 zile 1900

Numărul de porturi:
- 3 zile 3
- 5 zile 5
- 8 zile 8

Pret 2 RONI/KM. 
*/