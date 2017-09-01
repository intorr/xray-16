using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using Microsoft.Win32;
using XRay.ManagedApi.Core;
using XRay.ManagedApi.Core.Log;

namespace xrGlobalEditor
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private WindowLog logWindow;
        private WindowLightAnimEditor laEdWindow;

        public MainWindow()
        {
            InitializeComponent();
            Core.Initialize(Title, null, true);
        }

        private void MainWindow_Loaded(object sender, RoutedEventArgs e)
        {
            logWindow = new WindowLog { Owner = this };
            laEdWindow = new WindowLightAnimEditor { Owner = this };
            Logger.Log(Title, "initialized");
        }

        private void Menu_File_Open_Click(object sender, RoutedEventArgs e)
        {
            var openDialog = new OpenFileDialog
            {
                RestoreDirectory = true,
                Multiselect = false,
                Filter = "All Files (*.*)|*.*"
            };
            if (openDialog.ShowDialog() != true)
                return;
            var filename = openDialog.FileName;
            throw new NotImplementedException();
        }

        private void Menu_File_Save_Click(object sender, RoutedEventArgs e)
        {
            throw new NotImplementedException();
        }

        private void Menu_File_SaveAs_Click(object sender, RoutedEventArgs e)
        {
            var saveDialog = new SaveFileDialog
            {
                RestoreDirectory = true,
                Filter = "All Files (*.*)|*.*"
            };
            if (saveDialog.ShowDialog() != true)
                return;
            var filename = saveDialog.FileName;
            throw new NotImplementedException();
        }

        private void Menu_File_Clear_Click(object sender, RoutedEventArgs e)
        {
            throw new NotImplementedException();
        }

        private void Menu_Exit_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }

        private void Menu_Log_Click(object sender, RoutedEventArgs e)
        {
            if (!logWindow.IsVisible)
                logWindow.Show();
            else
                logWindow.Hide();
        }

        private void Menu_LightAnimEditor_Click(object sender, RoutedEventArgs e)
        {
            if (!laEdWindow.IsVisible)
                laEdWindow.Show();
            else
                laEdWindow.Hide();
        }

        private void MainWindow_OnClosing(object sender, CancelEventArgs e)
        {
            Core.Destroy();
        }
    }
}
