#!/usr/bin/python3

from PyQt5.QtWidgets import *
app = QApplication([])
window = QWidget()

pattern_label = QLabel('Pattern :')
text_label = QLabel('text :')
pattern_line_edit = QLineEdit()
text_line_edit = QLineEdit()
clear_button = QPushButton('Clear')
check_button = QPushButton('Check')
clear_button.setSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)
check_button.setSizePolicy(QSizePolicy.Fixed, QSizePolicy.Fixed)


layout = QVBoxLayout()
button_layout = QHBoxLayout()
button_layout.addWidget(check_button)
button_layout.addWidget(clear_button)
button_layout.addStretch(0)
layout.addWidget(pattern_label)
layout.addWidget(pattern_line_edit)
layout.addStretch(0)
layout.addWidget(text_label)
layout.addWidget(text_line_edit)
layout.addStretch(0)
layout.addLayout(button_layout)
window.setLayout(layout)
window.show()
app.exec()
