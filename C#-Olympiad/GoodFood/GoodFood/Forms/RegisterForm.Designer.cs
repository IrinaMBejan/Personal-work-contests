namespace GoodFood
{
    partial class RegisterForm
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
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.ParolaNou = new System.Windows.Forms.Label();
            this.Parola = new System.Windows.Forms.Label();
            this.Adresa = new System.Windows.Forms.Label();
            this.Prenume = new System.Windows.Forms.Label();
            this.Nume = new System.Windows.Forms.Label();
            this.Email = new System.Windows.Forms.Label();
            this.campParolaNou = new System.Windows.Forms.TextBox();
            this.campEmail = new System.Windows.Forms.TextBox();
            this.campPrenume = new System.Windows.Forms.TextBox();
            this.campAdresa = new System.Windows.Forms.TextBox();
            this.campNume = new System.Windows.Forms.TextBox();
            this.campParola = new System.Windows.Forms.TextBox();
            this.creareCont = new System.Windows.Forms.Button();
            this.errorLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.InitialImage = global::GoodFood.Properties.Resources.Restaurant;
            this.pictureBox1.Location = new System.Drawing.Point(204, 13);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(218, 75);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // ParolaNou
            // 
            this.ParolaNou.AutoSize = true;
            this.ParolaNou.Location = new System.Drawing.Point(69, 238);
            this.ParolaNou.Name = "ParolaNou";
            this.ParolaNou.Size = new System.Drawing.Size(136, 17);
            this.ParolaNou.TabIndex = 1;
            this.ParolaNou.Text = "Reintroduceti parola";
            // 
            // Parola
            // 
            this.Parola.AutoSize = true;
            this.Parola.Location = new System.Drawing.Point(69, 206);
            this.Parola.Name = "Parola";
            this.Parola.Size = new System.Drawing.Size(49, 17);
            this.Parola.TabIndex = 2;
            this.Parola.Text = "Parola";
            // 
            // Adresa
            // 
            this.Adresa.AutoSize = true;
            this.Adresa.Location = new System.Drawing.Point(69, 172);
            this.Adresa.Name = "Adresa";
            this.Adresa.Size = new System.Drawing.Size(53, 17);
            this.Adresa.TabIndex = 3;
            this.Adresa.Text = "Adresa";
            // 
            // Prenume
            // 
            this.Prenume.AutoSize = true;
            this.Prenume.Location = new System.Drawing.Point(69, 139);
            this.Prenume.Name = "Prenume";
            this.Prenume.Size = new System.Drawing.Size(65, 17);
            this.Prenume.TabIndex = 4;
            this.Prenume.Text = "Prenume";
            // 
            // Nume
            // 
            this.Nume.AutoSize = true;
            this.Nume.Location = new System.Drawing.Point(69, 107);
            this.Nume.Name = "Nume";
            this.Nume.Size = new System.Drawing.Size(45, 17);
            this.Nume.TabIndex = 5;
            this.Nume.Text = "Nume";
            // 
            // Email
            // 
            this.Email.AutoSize = true;
            this.Email.Location = new System.Drawing.Point(72, 268);
            this.Email.Name = "Email";
            this.Email.Size = new System.Drawing.Size(90, 17);
            this.Email.TabIndex = 6;
            this.Email.Text = "Adresa email";
            // 
            // campParolaNou
            // 
            this.campParolaNou.Location = new System.Drawing.Point(274, 238);
            this.campParolaNou.Name = "campParolaNou";
            this.campParolaNou.Size = new System.Drawing.Size(292, 22);
            this.campParolaNou.TabIndex = 7;
            this.campParolaNou.UseSystemPasswordChar = true;
            // 
            // campEmail
            // 
            this.campEmail.Location = new System.Drawing.Point(274, 268);
            this.campEmail.Name = "campEmail";
            this.campEmail.Size = new System.Drawing.Size(292, 22);
            this.campEmail.TabIndex = 8;
            // 
            // campPrenume
            // 
            this.campPrenume.Location = new System.Drawing.Point(274, 139);
            this.campPrenume.Name = "campPrenume";
            this.campPrenume.Size = new System.Drawing.Size(292, 22);
            this.campPrenume.TabIndex = 9;
            // 
            // campAdresa
            // 
            this.campAdresa.Location = new System.Drawing.Point(274, 173);
            this.campAdresa.Name = "campAdresa";
            this.campAdresa.Size = new System.Drawing.Size(292, 22);
            this.campAdresa.TabIndex = 10;
            // 
            // campNume
            // 
            this.campNume.Location = new System.Drawing.Point(274, 104);
            this.campNume.Name = "campNume";
            this.campNume.Size = new System.Drawing.Size(292, 22);
            this.campNume.TabIndex = 11;
            // 
            // campParola
            // 
            this.campParola.Location = new System.Drawing.Point(274, 206);
            this.campParola.Name = "campParola";
            this.campParola.Size = new System.Drawing.Size(292, 22);
            this.campParola.TabIndex = 12;
            this.campParola.UseSystemPasswordChar = true;
            // 
            // creareCont
            // 
            this.creareCont.Location = new System.Drawing.Point(204, 317);
            this.creareCont.Name = "creareCont";
            this.creareCont.Size = new System.Drawing.Size(218, 23);
            this.creareCont.TabIndex = 13;
            this.creareCont.Text = "Creare cont";
            this.creareCont.UseVisualStyleBackColor = true;
            this.creareCont.Click += new System.EventHandler(this.creareCont_Click);
            // 
            // errorLabel
            // 
            this.errorLabel.AutoSize = true;
            this.errorLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.errorLabel.Location = new System.Drawing.Point(72, 348);
            this.errorLabel.Name = "errorLabel";
            this.errorLabel.Size = new System.Drawing.Size(0, 20);
            this.errorLabel.TabIndex = 14;
            // 
            // RegisterForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(632, 390);
            this.Controls.Add(this.errorLabel);
            this.Controls.Add(this.creareCont);
            this.Controls.Add(this.campParola);
            this.Controls.Add(this.campNume);
            this.Controls.Add(this.campAdresa);
            this.Controls.Add(this.campPrenume);
            this.Controls.Add(this.campEmail);
            this.Controls.Add(this.campParolaNou);
            this.Controls.Add(this.Email);
            this.Controls.Add(this.Nume);
            this.Controls.Add(this.Prenume);
            this.Controls.Add(this.Adresa);
            this.Controls.Add(this.Parola);
            this.Controls.Add(this.ParolaNou);
            this.Controls.Add(this.pictureBox1);
            this.Name = "RegisterForm";
            this.Text = "Creare_cont_client";
            this.Load += new System.EventHandler(this.RegisterForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label ParolaNou;
        private System.Windows.Forms.Label Parola;
        private System.Windows.Forms.Label Adresa;
        private System.Windows.Forms.Label Prenume;
        private System.Windows.Forms.Label Nume;
        private System.Windows.Forms.Label Email;
        private System.Windows.Forms.TextBox campParolaNou;
        private System.Windows.Forms.TextBox campEmail;
        private System.Windows.Forms.TextBox campPrenume;
        private System.Windows.Forms.TextBox campAdresa;
        private System.Windows.Forms.TextBox campNume;
        private System.Windows.Forms.TextBox campParola;
        private System.Windows.Forms.Button creareCont;
        private System.Windows.Forms.Label errorLabel;
    }
}