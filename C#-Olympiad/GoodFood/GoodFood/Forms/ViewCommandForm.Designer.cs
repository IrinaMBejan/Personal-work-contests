namespace GoodFood.Forms
{
    partial class ViewCommandForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.campNecesarZilnic = new System.Windows.Forms.TextBox();
            this.campKcalTotal = new System.Windows.Forms.TextBox();
            this.campPretTotal = new System.Windows.Forms.TextBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.SalveazaComanda = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.AllowUserToDeleteRows = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(0, 0);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.ReadOnly = true;
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(714, 318);
            this.dataGridView1.TabIndex = 0;
            // 
            // campNecesarZilnic
            // 
            this.campNecesarZilnic.Location = new System.Drawing.Point(137, 336);
            this.campNecesarZilnic.Name = "campNecesarZilnic";
            this.campNecesarZilnic.ReadOnly = true;
            this.campNecesarZilnic.Size = new System.Drawing.Size(231, 22);
            this.campNecesarZilnic.TabIndex = 13;
            // 
            // campKcalTotal
            // 
            this.campKcalTotal.Location = new System.Drawing.Point(137, 363);
            this.campKcalTotal.Name = "campKcalTotal";
            this.campKcalTotal.ReadOnly = true;
            this.campKcalTotal.Size = new System.Drawing.Size(231, 22);
            this.campKcalTotal.TabIndex = 12;
            // 
            // campPretTotal
            // 
            this.campPretTotal.Location = new System.Drawing.Point(137, 388);
            this.campPretTotal.Name = "campPretTotal";
            this.campPretTotal.ReadOnly = true;
            this.campPretTotal.Size = new System.Drawing.Size(231, 22);
            this.campPretTotal.TabIndex = 11;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(28, 336);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(100, 17);
            this.label7.TabIndex = 10;
            this.label7.Text = "Necesar_zilnic";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(28, 363);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(73, 17);
            this.label6.TabIndex = 9;
            this.label6.Text = "Total_kcal";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(28, 393);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(69, 17);
            this.label5.TabIndex = 8;
            this.label5.Text = "Pret_total";
            // 
            // SalveazaComanda
            // 
            this.SalveazaComanda.Location = new System.Drawing.Point(507, 338);
            this.SalveazaComanda.Name = "SalveazaComanda";
            this.SalveazaComanda.Size = new System.Drawing.Size(195, 66);
            this.SalveazaComanda.TabIndex = 14;
            this.SalveazaComanda.Text = "Finalizare";
            this.SalveazaComanda.UseVisualStyleBackColor = true;
            this.SalveazaComanda.Click += new System.EventHandler(this.SalveazaComanda_Click);
            // 
            // ViewCommandForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(714, 435);
            this.Controls.Add(this.SalveazaComanda);
            this.Controls.Add(this.campNecesarZilnic);
            this.Controls.Add(this.campKcalTotal);
            this.Controls.Add(this.campPretTotal);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.dataGridView1);
            this.Name = "ViewCommandForm";
            this.Text = "Vizualizare_comanda";
            this.Load += new System.EventHandler(this.ViewCommandForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.TextBox campNecesarZilnic;
        private System.Windows.Forms.TextBox campKcalTotal;
        private System.Windows.Forms.TextBox campPretTotal;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Button SalveazaComanda;
    }
}