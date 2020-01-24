#include "Catch.hpp"

#include "samplewidgets00_no_accessor.h"

#include <QToolButton>

//! Ui::SampleWidgets is a private data member - tests will use findChild*()
TEST_CASE("SampleWidgets00 gobutton is initially unchecked")
{
    SampleWidgets00 widget;

    // The Ui is private, and the Go button is not in the public interface,
    // so we"cheat" and search for the contained widgets ourselves.
    // NOT A RECOMMENDED PRACTICE, especially in production code!!
    // This makes for potential maintenance pain in future, if the widget
    // internals are modified.
    // We improve the maintenance situation slightly by looking for
    // QAbstractButton instead of the more specific derived-class QToolButton.
    // This means our test code will still work if the implementations is
    // changed to use a different button type.
    auto gobutton = widget.findChild<QAbstractButton*>();

    // Will give a run-time test failure if SampleWidgets00 no longer has
    // a QToolButton
    // But won't detect a change to use a QToolButton for a totally different
    // purpose
    REQUIRE(gobutton != nullptr);

    CHECK(!gobutton->isChecked());
    CHECK(widget.answer() == 42);
}
