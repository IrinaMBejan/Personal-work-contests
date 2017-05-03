namespace Calatorie
{
    partial class Autentificare
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.Auten = new System.Windows.Forms.Button();
            this.campParola = new System.Windows.Forms.TextBox();
            this.campUser = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(81, 116);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(113, 26);
            this.label1.TabIndex = 0;
            this.label1.Text = "Username";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(81, 169);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(75, 26);
            this.label2.TabIndex = 1;
            this.label2.Text = "Parola";
            // 
            // Auten
            // 
            this.Auten.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Auten.Location = new System.Drawing.Point(263, 272);
            this.Auten.Name = "Auten";
            this.Auten.Size = new System.Drawing.Size(184, 53);
            this.Auten.TabIndex = 2;
            this.Auten.Text = "Autentificare";
            this.Auten.UseVisualStyleBackColor = true;
            this.Auten.Click += new System.EventHandler(this.Auten_Click);
            // 
            // campParola
            // 
            this.campParola.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.campParola.Location = new System.Drawing.Point(273, 163);
            this.campParola.Name = "campParola";
            this.campParola.PasswordChar = '*';
            this.campParola.Size = new System.Drawing.Size(390, 32);
            this.campParola.TabIndex = 3;
            this.campParola.UseSystemPasswordChar = true;
            // 
            // campUser
            // 
            this.campUser.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.campUser.Location = new System.Drawing.Point(273, 110);
            this.campUser.Name = "campUser";
            this.campUser.Size = new System.Drawing.Size(390, 32);
            this.campUser.TabIndex = 4;
            // 
            // Autentificare
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(736, 423);
            this.Controls.Add(this.campUser);
            this.Controls.Add(this.campParola);
            this.Controls.Add(this.Auten);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Autentificare";
            this.Text = "Autentificare";
            this.Load += new System.EventHandler(this.Autentificare_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button Auten;
        private System.Windows.Forms.TextBox campParola;
        private System.Windows.Forms.TextBox campUser;
    }
}

