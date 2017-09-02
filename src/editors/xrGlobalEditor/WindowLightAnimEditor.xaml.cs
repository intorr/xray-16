using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using XRay.ManagedApi.Core.Log;
using XRay.ManagedApi.Engine.LightAnimLibrary;

namespace xrGlobalEditor
{
    /// <summary>
    /// Логика взаимодействия для WindowLightAnimEditor.xaml
    /// </summary>
    public partial class WindowLightAnimEditor : Window
    {
        private LightAnimLibrary LALib;
        public WindowLightAnimEditor()
        {
            InitializeComponent();
            LALib = new LightAnimLibrary();
            LALib.Load();
            InitItems();
        }

        private void InitItems()
        {
            //listItems.ItemsSource = LALib.Objects();

            foreach (var item in LALib.Objects())
            {
                var buf = item.Name;
                string[] names = null;

                // Don't sure if this can happen.. Just in case
                if (buf.Contains('/') && buf.Contains('\\'))
                    Logger.Log("LightAnimEditor: WARNING! slash and backslash used both!!!");

                if (buf.Contains('/'))
                    names = buf.Split('/');

                if (buf.Contains('\\'))
                {
                    names = buf.Split('\\');
                    Logger.Log("LightAnimEditor: Warning! Deprecated backslash used");
                }

                if (names != null)
                {
                    buf = names[0].Replace(' ', '_');
                    if (!(listItems.FindName(buf) is TreeViewItem folder))
                    {
                        folder = new TreeViewItem { Name = buf, Header = names[0], Tag = item };
                        listItems.Items.Add(folder);
                        listItems.RegisterName(buf, folder);
                    }

                    var previousName = names[0];
                    var previousItem = folder;

                    // XXX: Review this code. Working incorrect in some cases
                    foreach (var name in names)
                    {
                        if (name == previousName && previousItem.FindName(name.Replace(' ','_')) != null)
                            continue;

                        previousName = name;
                        if (previousItem.FindName(buf) is TreeViewItem itembuf)
                            previousItem = itembuf;
                        buf = name.Replace(' ', '_');
                        

                        if (!(previousItem.FindName(buf) is TreeViewItem itm))
                        {
                            itm = new TreeViewItem { Name = buf, Header = name, Tag = item };
                            previousItem.Items.Add(itm);
                            previousItem.RegisterName(buf, itm);
                        }
                    }
                }
                else
                {
                    buf = item.Name.Replace(' ', '_');
                    listItems.Items.Add(new TreeViewItem { Name = buf, Header = item.Name, Tag = item });
                }
            }

            laItemsCount.Content = LALib.Objects().Length;
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            e.Cancel = true;
            Hide();
        }

        private void ReloadItems_Click(object sender, RoutedEventArgs e)
        {
            listItems.Items.Clear();
            listItems = null;
            listItems = new TreeView();
            LALib.Reload();
            InitItems();
        }

        private void listItems_SelectedItemChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (!(e.NewValue is TreeViewItem item))
                return;

            if (!(item.Tag is LightAnimItem laItem))
                return;

            tbLaName.Text = laItem.Name;
            tbLaName.IsEnabled = true;

            tbLaFPS.Text = laItem.FPS.ToString(CultureInfo.InvariantCulture);
            tbLaFPS.IsEnabled = true;

            tbLaFrameCount.Text = laItem.FrameCount.ToString();
            tbLaFrameCount.IsEnabled = true;

            //tbLaCurrentFrame.Text = laItem.Keys[0].ToString();
            //tbLaCurrentFrame.IsEnabled = true;

            //tbLaColor.SelectedColor = laItem.;
            //tbLaColor.IsEnabled = true;

            //tbLaAlpha.Text = laItem.;
            //tbLaAlpha.IsEnabled = true;
        }
    }
}
