#!/usr/bin/python3


import re
import gi

gi.require_version('Gtk', '4.0')
from gi.repository import Gtk, Gdk

class MyWindow(Gtk.ApplicationWindow):

    def __init__(self, **kargs):
        super().__init__(**kargs, title='Hello World')

        css_data = "#green { background-image: none; background-color: #00aa00; color: white; font-weight: bold; border-radius: 6px; margin-left: 4px; } #red {background-image: none; background-color: #cc0000; color: white; font-weight: bold; border-radius: 6px; margin-left: 4px;}"
        css_provider = Gtk.CssProvider()
        css_provider.load_from_data(css_data.encode())
        Gtk.StyleContext.add_provider_for_display(Gdk.Display.get_default(), css_provider, Gtk.STYLE_PROVIDER_PRIORITY_APPLICATION)

        button_box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL,spacing=6)
        vbox = Gtk.Box(orientation=Gtk.Orientation.VERTICAL,spacing=10)
        vbox.set_margin_top(10)
        vbox.set_margin_bottom(10)
        vbox.set_margin_start(10)
        vbox.set_margin_end(10)
        self.set_child(vbox)
        vbox.set_halign(align=Gtk.Align.FILL)
        vbox.set_valign(align=Gtk.Align.FILL)
        vbox.set_hexpand(True)

        pattern_label = Gtk.Label(label='Pattern :')
        pattern_label.set_halign(align=Gtk.Align.FILL)
        pattern_label.set_hexpand(True)
        pattern_label.set_xalign(0)
        vbox.append(pattern_label)
        
        self.pattern_entry = Gtk.Entry()
        self.pattern_entry.set_halign(Gtk.Align.FILL)
        self.pattern_entry.set_hexpand(True)
        vbox.append(self.pattern_entry)

        text_label = Gtk.Label(label='Text :')
        text_label.set_margin_top(10)
        text_label.set_xalign(0)
        vbox.append(pattern_label)
        text_label.set_halign(Gtk.Align.FILL)
        text_label.set_hexpand(True)
        vbox.append(text_label)

        self.text_entry = Gtk.Entry()
        self.text_entry.set_halign(Gtk.Align.FILL)
        self.text_entry.set_hexpand(True)
        vbox.append(self.text_entry)

        vbox.append(button_box)
        
        button_box.set_halign(align=Gtk.Align.FILL)
        button_box.set_margin_top(20)
        button_box.set_hexpand(True)
        check_button = Gtk.Button(label='Check')
        check_button.connect("clicked", self.on_check_button_clicked)
        check_button.set_halign(Gtk.Align.START)
        button_box.append(check_button)
        
        clear_button = Gtk.Button(label='Clear')
        clear_button.connect("clicked", self.on_clear_button_clicked)
        clear_button.set_halign(Gtk.Align.END)
        button_box.append(clear_button)


    def on_check_button_clicked(self, _widget):
        pattern_string = self.pattern_entry.get_buffer().get_text()
        text_string = self.text_entry.get_buffer().get_text()

        if not pattern_string or not text_string:
            self.text_entry.set_name('default')
            return

        print('Pattern = ', pattern_string)
        print('Text = ', text_string)
        pattern = re.compile(pattern_string)
        is_match = pattern.match(text_string)
        if is_match:
            self.text_entry.set_name('green')
        else:
            self.text_entry.set_name('red')


    def on_clear_button_clicked(self, _widget):
        self.pattern_entry.get_buffer().set_text("", -1)
        self.text_entry.get_buffer().set_text("", -1)
        self.text_entry.set_name('default')


def on_activate(app):
    # Create window
    win = MyWindow(application=app)
    win.present()


app = Gtk.Application(application_id='com.example.App')
app.connect('activate', on_activate)

app.run(None)

