#include "ChatView.h"
#include "Util.h"

ChatView::ChatView(QWidget *parent)
: QWebView(parent) {
    setObjectName("theChatView");
    setHtml(Util::readFile("resources/chat.html"));
    settings()->setUserStyleSheetUrl(QUrl::fromLocalFile("resources/chat.css"));
}
