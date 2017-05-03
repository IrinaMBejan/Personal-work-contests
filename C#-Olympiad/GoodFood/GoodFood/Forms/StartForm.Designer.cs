namespace GoodFood
{
    partial class StartForm
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
            this.MesajRestaurant = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.Logare = new System.Windows.Forms.Button();
            this.Inregistrare = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // MesajRestaurant
            // 
            this.MesajRestaurant.AutoSize = true;
            this.MesajRestaurant.Font = new System.Drawing.Font("Palatino Linotype", 10.8F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MesajRestaurant.Location = new System.Drawing.Point(185, 28);
            this.MesajRestaurant.Name = "MesajRestaurant";
            this.MesajRestaurant.Size = new System.Drawing.Size(233, 26);
            this.MesajRestaurant.TabIndex = 0;
            this.MesajRestaurant.Text = "Cel mai bun meniu din oras";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(65, 86);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(472, 131);
            this.pictureBox1.TabIndex = 1;
            this.pictureBox1.TabStop = false;
            // 
            // Logare
            // 
            this.Logare.Location = new System.Drawing.Point(366, 238);
            this.Logare.Name = "Logare";
            this.Logare.Size = new System.Drawing.Size(171, 23);
            this.Logare.TabIndex = 2;
            this.Logare.Text = "Logare";
            this.Logare.UseVisualStyleBackColor = true;
            this.Logare.Click += new System.EventHandler(this.Logare_Click);
            // 
            // Inregistrare
            // 
            this.Inregistrare.Location = new System.Drawing.Point(74, 238);
            this.Inregistrare.Name = "Inregistrare";
            this.Inregistrare.Size = new System.Drawing.Size(187, 23);
            this.Inregistrare.TabIndex = 3;
            this.Inregistrare.Text = "Inregistrare";
            this.Inregistrare.UseVisualStyleBackColor = true;
            this.Inregistrare.Click += new System.EventHandler(this.Inregistrare_Click);
            // 
            // StartForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(632, 303);
            this.Controls.Add(this.Inregistrare);
            this.Controls.Add(this.Logare);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.MesajRestaurant);
            this.Name = "StartForm";
            this.Text = "la";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label MesajRestaurant;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button Logare;
        private System.Windows.Forms.Button Inregistrare;
    }
}

