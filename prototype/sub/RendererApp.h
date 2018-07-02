#pragma once

#include "include/cef_app.h"
#include "include/wrapper/cef_message_router.h"

class RendererApp : public CefApp, public CefRenderProcessHandler {
public:
	RendererApp() 
	{
		CefMessageRouterConfig config;
		message_router_ = CefMessageRouterRendererSide::Create(config);
	}

	// CefApp methods:
	CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() OVERRIDE {
		return this;
	}

	// CefRenderProcessHandler methods:
	void OnWebKitInitialized() OVERRIDE {

		// Create the renderer-side router for query handling.
		CefMessageRouterConfig config;
		message_router_ = CefMessageRouterRendererSide::Create(config);
	}

	void OnContextCreated(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefV8Context> context) OVERRIDE {

		message_router_->OnContextCreated(browser, frame, context);
	}

	void OnContextReleased(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefV8Context> context) OVERRIDE {
		message_router_->OnContextReleased(browser, frame, context);
	}

	bool OnProcessMessageReceived(CefRefPtr<CefBrowser> browser,
		CefProcessId source_process,
		CefRefPtr<CefProcessMessage> message) OVERRIDE {

		return message_router_->OnProcessMessageReceived(browser, source_process,
			message);
	}

private:
	// Handles the renderer side of query routing.
	CefRefPtr<CefMessageRouterRendererSide> message_router_;

	IMPLEMENT_REFCOUNTING(RendererApp);
	DISALLOW_COPY_AND_ASSIGN(RendererApp);
};
