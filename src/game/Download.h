#ifndef DOWNLOAD_H
#define DOWNLOAD_H
#include <string>

class DownloadManager;
class Download
{
	std::string uri;
	void *http;
	bool keepAlive;

	char *downloadData;
	int downloadSize;
	int downloadStatus;

	const char *userID;
	const char *userSession;

	bool downloadFinished;
	bool downloadCanceled;
	bool downloadStarted;

public:
	Download(std::string uri, bool keepAlive = false);
	~Download();

	void AuthHeaders(const char *ID, const char *session);
	void Start();
	bool Reuse(std::string newuri);
	char* Finish(int *length, int *status);
	void Cancel();

	void CheckProgress(int *total, int *done);
	bool CheckDone();
	bool CheckCanceled();
	bool CheckStarted();

	friend class DownloadManager;
};

#endif
