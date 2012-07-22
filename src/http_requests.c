void http_response(struct evhttp_request *req, int http_code, char *msg,
	char *content, char *content_type) {
	
	struct evkeyvalq *response_headers = evhttp_request_get_output_headers(req);
  struct evbuffer *buffer = evbuffer_new();
		
	/* build body. */
  evbuffer_add_printf(buffer, "%s", content);
  
  /* Send reply */  
  evhttp_add_header(response_headers, "Content-Type", content_type);
  evhttp_add_header(response_headers, "Server", SERVER_NAME);
  evhttp_add_header(response_headers, "Cache-Control", "no-cache");
  evhttp_send_reply(req, http_code, msg, buffer);
  
  /* cleanup */
  evbuffer_free(buffer);
  return;
}
