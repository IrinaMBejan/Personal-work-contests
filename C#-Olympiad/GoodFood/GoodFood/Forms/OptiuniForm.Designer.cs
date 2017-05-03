namespace GoodFood.Forms
{
    partial class OptiuniForm
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
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle2 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea2 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend2 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series2 = new System.Windows.Forms.DataVisualization.Charting.Series();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.calculatorKcal = new System.Windows.Forms.TabPage();
            this.CalculateButton = new System.Windows.Forms.Button();
            this.campGreutate = new System.Windows.Forms.TextBox();
            this.campInaltime = new System.Windows.Forms.TextBox();
            this.campVarsta = new System.Windows.Forms.TextBox();
            this.campCalorii = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.comanda = new System.Windows.Forms.TabPage();
            this.campNecesarZilnic = new System.Windows.Forms.TextBox();
            this.campKcalTotal = new System.Windows.Forms.TextBox();
            this.campPretTotal = new System.Windows.Forms.TextBox();
            this.comandButton = new System.Windows.Forms.Button();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.meniuBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.gOOD_FOODDataSet = new GoodFood.GOOD_FOODDataSet();
            this.generareMenu = new System.Windows.Forms.TabPage();
            this.graphicKcal = new System.Windows.Forms.TabPage();
            this.meniuTableAdapter = new GoodFood.GOOD_FOODDataSetTableAdapters.MeniuTableAdapter();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.idprodusDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.denumireprodusDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.descriereDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.pretDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.kcalDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.felulDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Cantitate = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.chart1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.dataGridView2 = new System.Windows.Forms.DataGridView();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.buget = new System.Windows.Forms.TextBox();
            this.campCaloriiNecesare = new System.Windows.Forms.TextBox();
            this.Generator = new System.Windows.Forms.Button();
            this.tabControl1.SuspendLayout();
            this.calculatorKcal.SuspendLayout();
            this.comanda.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.meniuBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.gOOD_FOODDataSet)).BeginInit();
            this.generareMenu.SuspendLayout();
            this.graphicKcal.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).BeginInit();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.calculatorKcal);
            this.tabControl1.Controls.Add(this.comanda);
            this.tabControl1.Controls.Add(this.generareMenu);
            this.tabControl1.Controls.Add(this.graphicKcal);
            this.tabControl1.Location = new System.Drawing.Point(0, 0);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(910, 451);
            this.tabControl1.TabIndex = 0;
            // 
            // calculatorKcal
            // 
            this.calculatorKcal.Controls.Add(this.CalculateButton);
            this.calculatorKcal.Controls.Add(this.campGreutate);
            this.calculatorKcal.Controls.Add(this.campInaltime);
            this.calculatorKcal.Controls.Add(this.campVarsta);
            this.calculatorKcal.Controls.Add(this.campCalorii);
            this.calculatorKcal.Controls.Add(this.label4);
            this.calculatorKcal.Controls.Add(this.label3);
            this.calculatorKcal.Controls.Add(this.label2);
            this.calculatorKcal.Controls.Add(this.label1);
            this.calculatorKcal.Font = new System.Drawing.Font("Palatino Linotype", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.calculatorKcal.Location = new System.Drawing.Point(4, 25);
            this.calculatorKcal.Name = "calculatorKcal";
            this.calculatorKcal.Padding = new System.Windows.Forms.Padding(3);
            this.calculatorKcal.Size = new System.Drawing.Size(902, 422);
            this.calculatorKcal.TabIndex = 0;
            this.calculatorKcal.Text = "CalculatorKcal";
            this.calculatorKcal.UseVisualStyleBackColor = true;
            // 
            // CalculateButton
            // 
            this.CalculateButton.Font = new System.Drawing.Font("Palatino Linotype", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CalculateButton.Location = new System.Drawing.Point(126, 310);
            this.CalculateButton.Name = "CalculateButton";
            this.CalculateButton.Size = new System.Drawing.Size(101, 47);
            this.CalculateButton.TabIndex = 8;
            this.CalculateButton.Text = "Calculeaza";
            this.CalculateButton.UseVisualStyleBackColor = true;
            this.CalculateButton.Click += new System.EventHandler(this.CalculateButton_Click);
            // 
            // campGreutate
            // 
            this.campGreutate.Font = new System.Drawing.Font("Palatino Linotype", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.campGreutate.Location = new System.Drawing.Point(189, 223);
            this.campGreutate.Name = "campGreutate";
            this.campGreutate.Size = new System.Drawing.Size(192, 30);
            this.campGreutate.TabIndex = 7;
            // 
            // campInaltime
            // 
            this.campInaltime.Font = new System.Drawing.Font("Palatino Linotype", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.campInaltime.Location = new System.Drawing.Point(189, 147);
            this.campInaltime.Name = "campInaltime";
            this.campInaltime.Size = new System.Drawing.Size(192, 30);
            this.campInaltime.TabIndex = 6;
            // 
            // campVarsta
            // 
            this.campVarsta.Font = new System.Drawing.Font("Palatino Linotype", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.campVarsta.Location = new System.Drawing.Point(189, 65);
            this.campVarsta.Name = "campVarsta";
            this.campVarsta.Size = new System.Drawing.Size(192, 30);
            this.campVarsta.TabIndex = 5;
            // 
            // campCalorii
            // 
            this.campCalorii.Font = new System.Drawing.Font("Palatino Linotype", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.campCalorii.Location = new System.Drawing.Point(524, 147);
            this.campCalorii.Name = "campCalorii";
            this.campCalorii.ReadOnly = true;
            this.campCalorii.Size = new System.Drawing.Size(140, 30);
            this.campCalorii.TabIndex = 4;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Palatino Linotype", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(470, 147);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(48, 23);
            this.label4.TabIndex = 3;
            this.label4.Text = "Kcal:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Palatino Linotype", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(69, 228);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(112, 23);
            this.label3.TabIndex = 2;
            this.label3.Text = "Greutate(cm)";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Palatino Linotype", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(69, 154);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(108, 23);
            this.label2.TabIndex = 1;
            this.label2.Text = "Inaltime(cm)";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Palatino Linotype", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(69, 70);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(97, 23);
            this.label1.TabIndex = 0;
            this.label1.Text = "Varsta(ani)";
            // 
            // comanda
            // 
            this.comanda.Controls.Add(this.campNecesarZilnic);
            this.comanda.Controls.Add(this.campKcalTotal);
            this.comanda.Controls.Add(this.campPretTotal);
            this.comanda.Controls.Add(this.comandButton);
            this.comanda.Controls.Add(this.label7);
            this.comanda.Controls.Add(this.label6);
            this.comanda.Controls.Add(this.label5);
            this.comanda.Controls.Add(this.dataGridView1);
            this.comanda.Location = new System.Drawing.Point(4, 25);
            this.comanda.Name = "comanda";
            this.comanda.Padding = new System.Windows.Forms.Padding(3);
            this.comanda.Size = new System.Drawing.Size(902, 422);
            this.comanda.TabIndex = 1;
            this.comanda.Text = "Comanda";
            this.comanda.UseVisualStyleBackColor = true;
            // 
            // campNecesarZilnic
            // 
            this.campNecesarZilnic.Location = new System.Drawing.Point(137, 330);
            this.campNecesarZilnic.Name = "campNecesarZilnic";
            this.campNecesarZilnic.ReadOnly = true;
            this.campNecesarZilnic.Size = new System.Drawing.Size(231, 22);
            this.campNecesarZilnic.TabIndex = 7;
            // 
            // campKcalTotal
            // 
            this.campKcalTotal.Location = new System.Drawing.Point(137, 357);
            this.campKcalTotal.Name = "campKcalTotal";
            this.campKcalTotal.ReadOnly = true;
            this.campKcalTotal.Size = new System.Drawing.Size(231, 22);
            this.campKcalTotal.TabIndex = 6;
            // 
            // campPretTotal
            // 
            this.campPretTotal.Location = new System.Drawing.Point(137, 382);
            this.campPretTotal.Name = "campPretTotal";
            this.campPretTotal.ReadOnly = true;
            this.campPretTotal.Size = new System.Drawing.Size(231, 22);
            this.campPretTotal.TabIndex = 5;
            // 
            // comandButton
            // 
            this.comandButton.Location = new System.Drawing.Point(718, 330);
            this.comandButton.Name = "comandButton";
            this.comandButton.Size = new System.Drawing.Size(173, 83);
            this.comandButton.TabIndex = 4;
            this.comandButton.Text = "Comanda";
            this.comandButton.UseVisualStyleBackColor = true;
            this.comandButton.Click += new System.EventHandler(this.comandButton_Click);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(28, 330);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(100, 17);
            this.label7.TabIndex = 3;
            this.label7.Text = "Necesar_zilnic";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(28, 357);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(73, 17);
            this.label6.TabIndex = 2;
            this.label6.Text = "Total_kcal";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(28, 387);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(69, 17);
            this.label5.TabIndex = 1;
            this.label5.Text = "Pret_total";
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToDeleteRows = false;
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.idprodusDataGridViewTextBoxColumn,
            this.denumireprodusDataGridViewTextBoxColumn,
            this.descriereDataGridViewTextBoxColumn,
            this.pretDataGridViewTextBoxColumn,
            this.kcalDataGridViewTextBoxColumn,
            this.felulDataGridViewTextBoxColumn,
            this.Cantitate});
            this.dataGridView1.DataSource = this.meniuBindingSource;
            this.dataGridView1.Location = new System.Drawing.Point(-3, 0);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 24;
            this.dataGridView1.Size = new System.Drawing.Size(902, 311);
            this.dataGridView1.TabIndex = 0;
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
            // 
            // meniuBindingSource
            // 
            this.meniuBindingSource.DataMember = "Meniu";
            this.meniuBindingSource.DataSource = this.gOOD_FOODDataSet;
            // 
            // gOOD_FOODDataSet
            // 
            this.gOOD_FOODDataSet.DataSetName = "GOOD_FOODDataSet";
            this.gOOD_FOODDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // generareMenu
            // 
            this.generareMenu.Controls.Add(this.Generator);
            this.generareMenu.Controls.Add(this.campCaloriiNecesare);
            this.generareMenu.Controls.Add(this.buget);
            this.generareMenu.Controls.Add(this.label9);
            this.generareMenu.Controls.Add(this.label8);
            this.generareMenu.Controls.Add(this.dataGridView2);
            this.generareMenu.Location = new System.Drawing.Point(4, 25);
            this.generareMenu.Name = "generareMenu";
            this.generareMenu.Padding = new System.Windows.Forms.Padding(3);
            this.generareMenu.Size = new System.Drawing.Size(902, 422);
            this.generareMenu.TabIndex = 2;
            this.generareMenu.Text = "Generare Meniu";
            this.generareMenu.UseVisualStyleBackColor = true;
            // 
            // graphicKcal
            // 
            this.graphicKcal.Controls.Add(this.chart1);
            this.graphicKcal.Location = new System.Drawing.Point(4, 25);
            this.graphicKcal.Name = "graphicKcal";
            this.graphicKcal.Padding = new System.Windows.Forms.Padding(3);
            this.graphicKcal.Size = new System.Drawing.Size(902, 422);
            this.graphicKcal.TabIndex = 3;
            this.graphicKcal.Text = "Grafic Kcal";
            this.graphicKcal.UseVisualStyleBackColor = true;
            // 
            // meniuTableAdapter
            // 
            this.meniuTableAdapter.ClearBeforeFill = true;
            // 
            // idprodusDataGridViewTextBoxColumn
            // 
            this.idprodusDataGridViewTextBoxColumn.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.idprodusDataGridViewTextBoxColumn.DataPropertyName = "id_produs";
            this.idprodusDataGridViewTextBoxColumn.HeaderText = "id_produs";
            this.idprodusDataGridViewTextBoxColumn.Name = "idprodusDataGridViewTextBoxColumn";
            this.idprodusDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // denumireprodusDataGridViewTextBoxColumn
            // 
            this.denumireprodusDataGridViewTextBoxColumn.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.denumireprodusDataGridViewTextBoxColumn.DataPropertyName = "denumire_produs";
            this.denumireprodusDataGridViewTextBoxColumn.HeaderText = "denumire_produs";
            this.denumireprodusDataGridViewTextBoxColumn.Name = "denumireprodusDataGridViewTextBoxColumn";
            this.denumireprodusDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // descriereDataGridViewTextBoxColumn
            // 
            this.descriereDataGridViewTextBoxColumn.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.descriereDataGridViewTextBoxColumn.DataPropertyName = "descriere";
            this.descriereDataGridViewTextBoxColumn.HeaderText = "descriere";
            this.descriereDataGridViewTextBoxColumn.Name = "descriereDataGridViewTextBoxColumn";
            this.descriereDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // pretDataGridViewTextBoxColumn
            // 
            this.pretDataGridViewTextBoxColumn.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.pretDataGridViewTextBoxColumn.DataPropertyName = "pret";
            this.pretDataGridViewTextBoxColumn.HeaderText = "pret";
            this.pretDataGridViewTextBoxColumn.Name = "pretDataGridViewTextBoxColumn";
            this.pretDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // kcalDataGridViewTextBoxColumn
            // 
            this.kcalDataGridViewTextBoxColumn.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.kcalDataGridViewTextBoxColumn.DataPropertyName = "kcal";
            this.kcalDataGridViewTextBoxColumn.HeaderText = "kcal";
            this.kcalDataGridViewTextBoxColumn.Name = "kcalDataGridViewTextBoxColumn";
            this.kcalDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // felulDataGridViewTextBoxColumn
            // 
            this.felulDataGridViewTextBoxColumn.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            this.felulDataGridViewTextBoxColumn.DataPropertyName = "felul";
            this.felulDataGridViewTextBoxColumn.HeaderText = "felul";
            this.felulDataGridViewTextBoxColumn.Name = "felulDataGridViewTextBoxColumn";
            this.felulDataGridViewTextBoxColumn.ReadOnly = true;
            // 
            // Cantitate
            // 
            this.Cantitate.AutoSizeMode = System.Windows.Forms.DataGridViewAutoSizeColumnMode.Fill;
            dataGridViewCellStyle2.NullValue = "1";
            this.Cantitate.DefaultCellStyle = dataGridViewCellStyle2;
            this.Cantitate.HeaderText = "cantitate";
            this.Cantitate.Name = "Cantitate";
            // 
            // chart1
            // 
            chartArea2.Name = "ChartArea1";
            this.chart1.ChartAreas.Add(chartArea2);
            legend2.Name = "Legend1";
            this.chart1.Legends.Add(legend2);
            this.chart1.Location = new System.Drawing.Point(0, 0);
            this.chart1.Name = "chart1";
            series2.ChartArea = "ChartArea1";
            series2.Legend = "Legend1";
            series2.Name = "Series1";
            this.chart1.Series.Add(series2);
            this.chart1.Size = new System.Drawing.Size(906, 422);
            this.chart1.TabIndex = 0;
            this.chart1.Text = "chart1";
            this.chart1.Click += new System.EventHandler(this.chart1_Click);
            // 
            // dataGridView2
            // 
            this.dataGridView2.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView2.Location = new System.Drawing.Point(3, 113);
            this.dataGridView2.Name = "dataGridView2";
            this.dataGridView2.RowTemplate.Height = 24;
            this.dataGridView2.Size = new System.Drawing.Size(899, 306);
            this.dataGridView2.TabIndex = 0;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(23, 25);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(145, 17);
            this.label8.TabIndex = 1;
            this.label8.Text = "Necesar zilnic de kcal";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(23, 61);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(45, 17);
            this.label9.TabIndex = 2;
            this.label9.Text = "Buget";
            // 
            // buget
            // 
            this.buget.Location = new System.Drawing.Point(174, 58);
            this.buget.Name = "buget";
            this.buget.Size = new System.Drawing.Size(155, 22);
            this.buget.TabIndex = 3;
            // 
            // campCaloriiNecesare
            // 
            this.campCaloriiNecesare.Location = new System.Drawing.Point(174, 25);
            this.campCaloriiNecesare.Name = "campCaloriiNecesare";
            this.campCaloriiNecesare.ReadOnly = true;
            this.campCaloriiNecesare.Size = new System.Drawing.Size(155, 22);
            this.campCaloriiNecesare.TabIndex = 4;
            // 
            // Generator
            // 
            this.Generator.Location = new System.Drawing.Point(335, 25);
            this.Generator.Name = "Generator";
            this.Generator.Size = new System.Drawing.Size(556, 58);
            this.Generator.TabIndex = 5;
            this.Generator.Text = "Genereaza";
            this.Generator.UseVisualStyleBackColor = true;
            this.Generator.Click += new System.EventHandler(this.Generator_Click);
            // 
            // OptiuniForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(907, 450);
            this.Controls.Add(this.tabControl1);
            this.Name = "OptiuniForm";
            this.Text = "OptiuniForm";
            this.Load += new System.EventHandler(this.OptiuniForm_Load);
            this.tabControl1.ResumeLayout(false);
            this.calculatorKcal.ResumeLayout(false);
            this.calculatorKcal.PerformLayout();
            this.comanda.ResumeLayout(false);
            this.comanda.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.meniuBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gOOD_FOODDataSet)).EndInit();
            this.generareMenu.ResumeLayout(false);
            this.generareMenu.PerformLayout();
            this.graphicKcal.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView2)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage calculatorKcal;
        private System.Windows.Forms.TabPage comanda;
        private System.Windows.Forms.TabPage generareMenu;
        private System.Windows.Forms.TabPage graphicKcal;
        private System.Windows.Forms.Button CalculateButton;
        private System.Windows.Forms.TextBox campGreutate;
        private System.Windows.Forms.TextBox campInaltime;
        private System.Windows.Forms.TextBox campVarsta;
        private System.Windows.Forms.TextBox campCalorii;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DataGridView dataGridView1;
        private GOOD_FOODDataSet gOOD_FOODDataSet;
        private System.Windows.Forms.BindingSource meniuBindingSource;
        private GOOD_FOODDataSetTableAdapters.MeniuTableAdapter meniuTableAdapter;
        private System.Windows.Forms.TextBox campNecesarZilnic;
        private System.Windows.Forms.TextBox campKcalTotal;
        private System.Windows.Forms.TextBox campPretTotal;
        private System.Windows.Forms.Button comandButton;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label5;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.Windows.Forms.DataGridViewTextBoxColumn idprodusDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn denumireprodusDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn descriereDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn pretDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn kcalDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn felulDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn Cantitate;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart1;
        private System.Windows.Forms.DataGridView dataGridView2;
        private System.Windows.Forms.Button Generator;
        private System.Windows.Forms.TextBox campCaloriiNecesare;
        private System.Windows.Forms.TextBox buget;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label8;
    }
}