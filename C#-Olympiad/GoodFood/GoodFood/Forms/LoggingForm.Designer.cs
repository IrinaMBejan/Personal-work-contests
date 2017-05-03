namespace GoodFood.Forms
{
    partial class LoggingForm
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
            this.campParola = new System.Windows.Forms.TextBox();
            this.campEmail = new System.Windows.Forms.TextBox();
            this.Intra = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(86, 60);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(90, 17);
            this.label1.TabIndex = 0;
            this.label1.Text = "Adresa email";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(86, 111);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(49, 17);
            this.label2.TabIndex = 1;
            this.label2.Text = "Parola";
            // 
            // campParola
            // 
            this.campParola.Location = new System.Drawing.Point(307, 106);
            this.campParola.Name = "campParola";
            this.campParola.Size = new System.Drawing.Size(240, 22);
            this.campParola.TabIndex = 2;
            this.campParola.UseSystemPasswordChar = true;
            // 
            // campEmail
            // 
            this.campEmail.Location = new System.Drawing.Point(307, 55);
            this.campEmail.Name = "campEmail";
            this.campEmail.Size = new System.Drawing.Size(240, 22);
            this.campEmail.TabIndex = 3;
            // 
            // Intra
            // 
            this.Intra.Location = new System.Drawing.Point(206, 210);
            this.Intra.Name = "Intra";
            this.Intra.Size = new System.Drawing.Size(209, 42);
            this.Intra.TabIndex = 4;
            this.Intra.Text = "Intra";
            this.Intra.UseVisualStyleBackColor = true;
            this.Intra.Click += new System.EventHandler(this.Intra_Click);
            // 
            // LoggingForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(632, 303);
            this.Controls.Add(this.Intra);
            this.Controls.Add(this.campEmail);
            this.Controls.Add(this.campParola);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "LoggingForm";
            this.Text = "Autentificare_client";
            this.Load += new System.EventHandler(this.LoggingForm_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox campParola;
        private System.Windows.Forms.TextBox campEmail;
        private System.Windows.Forms.Button Intra;
    }
}