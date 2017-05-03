namespace Calatorie.Forms
{
    partial class Administrare
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
            this.Intializare = new System.Windows.Forms.Button();
            this.Salvare = new System.Windows.Forms.Button();
            this.Actualizare = new System.Windows.Forms.Button();
            this.Generare = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.Lista = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // Intializare
            // 
            this.Intializare.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Intializare.Location = new System.Drawing.Point(978, 32);
            this.Intializare.Name = "Intializare";
            this.Intializare.Size = new System.Drawing.Size(209, 84);
            this.Intializare.TabIndex = 0;
            this.Intializare.Text = "Initializare";
            this.Intializare.UseVisualStyleBackColor = true;
            this.Intializare.Click += new System.EventHandler(this.Intializare_Click);
            // 
            // Salvare
            // 
            this.Salvare.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Salvare.Location = new System.Drawing.Point(978, 223);
            this.Salvare.Name = "Salvare";
            this.Salvare.Size = new System.Drawing.Size(209, 84);
            this.Salvare.TabIndex = 1;
            this.Salvare.Text = "Salvare coordonate";
            this.Salvare.UseVisualStyleBackColor = true;
            this.Salvare.Click += new System.EventHandler(this.Salvare_Click);
            // 
            // Actualizare
            // 
            this.Actualizare.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Actualizare.Location = new System.Drawing.Point(978, 331);
            this.Actualizare.Name = "Actualizare";
            this.Actualizare.Size = new System.Drawing.Size(209, 84);
            this.Actualizare.TabIndex = 2;
            this.Actualizare.Text = "Actualizare distante";
            this.Actualizare.UseVisualStyleBackColor = true;
            this.Actualizare.Click += new System.EventHandler(this.Actualizare_Click);
            // 
            // Generare
            // 
            this.Generare.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Generare.Location = new System.Drawing.Point(978, 439);
            this.Generare.Name = "Generare";
            this.Generare.Size = new System.Drawing.Size(209, 84);
            this.Generare.TabIndex = 3;
            this.Generare.Text = "Generare croaziere";
            this.Generare.UseVisualStyleBackColor = true;
            this.Generare.Click += new System.EventHandler(this.Generare_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.InitialImage = global::Calatorie.Properties.Resources.MareaNeagra;
            this.pictureBox1.Location = new System.Drawing.Point(32, 32);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(800, 600);
            this.pictureBox1.TabIndex = 4;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Click += new System.EventHandler(this.pictureBox1_Click);
            this.pictureBox1.MouseClick += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseClick);
            // 
            // Lista
            // 
            this.Lista.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Lista.Location = new System.Drawing.Point(978, 548);
            this.Lista.Name = "Lista";
            this.Lista.Size = new System.Drawing.Size(209, 84);
            this.Lista.TabIndex = 5;
            this.Lista.Text = "Lista croaziere";
            this.Lista.UseVisualStyleBackColor = true;
            // 
            // Administrare
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1270, 651);
            this.Controls.Add(this.Lista);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.Generare);
            this.Controls.Add(this.Actualizare);
            this.Controls.Add(this.Salvare);
            this.Controls.Add(this.Intializare);
            this.Name = "Administrare";
            this.Text = "Administrare";
            this.Load += new System.EventHandler(this.Administrare_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button Intializare;
        private System.Windows.Forms.Button Salvare;
        private System.Windows.Forms.Button Actualizare;
        private System.Windows.Forms.Button Generare;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button Lista;
    }
}