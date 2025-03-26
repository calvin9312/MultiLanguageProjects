use iced::widget::{container, center, button, row, column, text_input, horizontal_space, vertical_space};
use iced::{alignment, Element, Color, Theme};


const RED    : Color = Color::from_rgb(1.0, 0.0, 0.0);
const GREEN  : Color = Color::from_rgb(0.0, 1.0, 0.0);
const YELLOW : Color = Color::from_rgb(1.0, 1.0, 0.0);

fn main() -> iced::Result {
    iced::application("Regular Expression Validator", Example::update, Example::view)
        .run()
}

#[derive(Default)]
struct Example {
    pattern :String,
    text :String,
    //input_style_default :iced::widget::text_input::Style,
    //input_style_green :iced::widget::text_input::Style,
    //input_style_red :iced::widget::text_input::Style,
}

#[derive(Debug, Clone)]
enum Message {
    CheckPressed,
    ClearPressed,
    PatternInput(String),
    TextInput(String),
}

impl Example {
    fn update(&mut self, message: Message) {
        match message {
            Message::CheckPressed => {
            }
            Message::ClearPressed => {
                self.text = "".to_string();
                self.pattern = "".to_string();
            }
            Message::PatternInput(pattern) => {
                self.pattern = pattern;
            }
            Message::TextInput(text) => {
                self.text = text;
            }
        }
    }

    fn view(&self) -> Element<Message> {

        let buttons = row![
            button("check").on_press(Message::CheckPressed),
            button("clear").on_press(Message::ClearPressed),
            horizontal_space(),
        ]
        .spacing(10);

        let pattern_input = text_input("", &self.pattern).on_input(Message::PatternInput);

        let text_input = text_input("", &self.text).on_input(Message::TextInput);

        let pattern_label = row![
            "Pattern",
            horizontal_space(),
        ];

        let text_label = row![
            "Text",
            horizontal_space(),
        ];

        let pattern_label_and_text = column![
            pattern_label,
            pattern_input,
        ];

        let text_label_and_text = column![
            text_label,
            text_input,
        ];

        let content = column![
            pattern_label_and_text,
            text_label_and_text,
            buttons,
        ]
        .spacing(20)
        .padding(20)
        .align_x(alignment::Horizontal::Left);

        //center(content).into()
        container(content).into()
    }
}

//fn test_input_green_style(theme: &Theme) -> text_input::Style {
    //text_input::Style {
        //background: GREEN,
    //}
//}

//fn test_input_red_style(theme: &Theme) -> text_input::Style {
    //text_input::Style {
        //background: RED,
    //}
//}

