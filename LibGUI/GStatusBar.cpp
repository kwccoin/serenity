#include <LibGUI/GStatusBar.h>
#include <LibGUI/GLabel.h>
#include <LibGUI/GBoxLayout.h>
#include <SharedGraphics/Painter.h>

GStatusBar::GStatusBar(GWidget* parent)
    : GWidget(parent)
{
    set_size_policy(SizePolicy::Fill, SizePolicy::Fixed);
    set_preferred_size({ 0, 16 });
    set_layout(make<GBoxLayout>(Orientation::Horizontal));
    m_label = new GLabel(this);
    m_label->set_fill_with_background_color(false);
}

GStatusBar::~GStatusBar()
{
}

void GStatusBar::set_text(String&& text)
{
    m_label->set_text(move(text));
}

String GStatusBar::text() const
{
    return m_label->text();
}

void GStatusBar::paint_event(GPaintEvent&)
{
    Painter painter(*this);
    painter.fill_rect({ 0, 1, width(), height() - 1 }, Color::LightGray);
    painter.draw_line({ 0, 0 }, { width() - 1, 0 }, Color::DarkGray);
}