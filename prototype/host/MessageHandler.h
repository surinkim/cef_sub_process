#pragma once

#include "include/cef_client.h"
#include "include/wrapper/cef_message_router.h"

const char kTestMessageName[] = "MessageRouterTest";

// Handle messages in the browser process.
class MessageHandler : public CefMessageRouterBrowserSide::Handler {
public:
	explicit MessageHandler(const CefString& startup_url)
		: startup_url_(startup_url) {}

	// Called due to cefQuery execution in message_router.html.
	bool OnQuery(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		int64 query_id,
		const CefString& request,
		bool persistent,
		CefRefPtr<Callback> callback) OVERRIDE {

		const std::string& message_name = request;
		callback->Success(message_name);
		return true;

		//// Only handle messages from the startup URL.
		//const std::string& url = frame->GetURL();
		//if (url.find(startup_url_) != 0)
		//	return false;

		//const std::string& message_name = request;
		//if (message_name.find(kTestMessageName) == 0) {
		//	// Reverse the string and return.
		//	std::string result = message_name.substr(sizeof(kTestMessageName));
		//	std::reverse(result.begin(), result.end());
		//	callback->Success(result);
		//	return true;
		//}

		return false;
	}

private:
	const CefString startup_url_;

	DISALLOW_COPY_AND_ASSIGN(MessageHandler);
};
