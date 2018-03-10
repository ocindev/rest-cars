class APIService {
public:
	APIService();
	void handle(struct ns_connection *nc, struct http_message *hm);
};
