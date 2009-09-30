//-*- mode: c++; tab-width: 4; indent-tabs-mode: t; c-file-style: "stroustrup"; -*-
// This file is part of wkhtmltopdf.
//
// wkhtmltopdf is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// wkhtmltopdf is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with wkhtmltopdf.  If not, see <http://www.gnu.org/licenses/>.
#ifndef __wkhtmltopdf_hh__
#define __wkhtmltopdf_hh__
#include <QtWebKit>
#include <QObject>
#include <QtGui>
#include <QWebView>
#include <QNetworkProxy>
#include <QAtomicInt>
#include <stdlib.h>
#include <QMap>
#include <QString>
#include <QVector>
#ifdef  __EXTENSIVE_WKHTMLTOPDF_QT_HACK__
#include "toc.hh"
#endif

class WkHtmlToPdfFeedback {
public slots:
	void convertionError(const QString & message);
	void convertionWarning(const QString & message);
	void stateChanged();
	void progressChanged();
};


// class WKHtmlToPdf;

// //Class responsible for describing and handling a command line argument
// struct ArgHandler {
// 	QString longName, desc; //Long -- style name and the description of the switch
// 	char shortSwitch; //Short - style name, 0 if no short switch
// 	QVector<QString> argn; //The name of the arguments to the switch.
// 	bool display;
// 	//Called whenever an argument is parsed
// 	virtual bool operator() (const char ** args, WKHtmlToPdf * w) = 0;
// 	virtual void useDefault() {};
// 	virtual QString getDesc() const {
// 		return desc;
// 	}
// 	virtual ~ArgHandler() {};
// };

// //Class responsible for the convertion
// class WKHtmlToPdf : public QObject {
// 	Q_OBJECT
// public:
// 	QPrinter * printer;

// 	//The webpages is used to fetch and render the webpages using webkit
// 	QVector<QWebPage *> pages;
// 	QVector<uint> pageStart;

// 	QVector<QWebPage *> headers;
// 	QVector<QWebPage *> footers;


// 	//Configuration variabels
// 	QVector<const char *> in; //Names of the input files
// 	const char * out; //Name of the output file
// 	QNetworkAccessManager * am;

// 	QNetworkProxy::ProxyType proxyType; //Type of proxy to use
// 	int proxyPort; //The port of the proxy to use
// 	const char * proxyHost; //The host name of the proxy to use or NULL
// 	const char * proxyUser; //Username for the said broxy or NULL
// 	const char * proxyPassword; //Password for the said broxy or NULL
// 	const char * username;
// 	const char * password;
// 	bool quiet; //Be less verbose
// 	bool background; //Should we print the background?
// 	bool print_toc;
// 	bool enable_plugins;
// 	bool use_x11;
// 	bool useExternalLinks;
// 	bool useLocalLinks;
// 	bool disable_javascript; //Should we disable javascript
// 	bool disable_intelligent_shrinking;
// 	int jsredirectwait; //How meny milliseconds should we wait for a javascrit redirect
// 	QPrinter::PageSize pageSize; //What size paper should we use
// 	QPrinter::Orientation orientation; //What orientation
// 	QPrinter::ColorMode colorMode; //Color or grayscale
// 	QPrinter::PrinterMode resolution; //resolution
// 	int dpi; //The printing dpi
// 	int page_offset;
// 	int copies;
// 	bool collate;

// 	float zoom_factor;
// 	//Specify page margins
// 	QPair<qreal, QPrinter::Unit> margin_top;
// 	QPair<qreal, QPrinter::Unit> margin_right;
// 	QPair<qreal, QPrinter::Unit> margin_bottom;
// 	QPair<qreal, QPrinter::Unit> margin_left;
// 	bool printMediaType;
// 	const char * default_encoding;
// 	const char * user_style_sheet;

// 	const char * cover;
// 	bool outline;
// 	//Header / footer settings
// 	int header_font_size, footer_font_size;
// 	const char * header_font_name, * footer_font_name;
// 	QString header_left, header_center, header_right;
// 	bool header_line, footer_line;
// 	QString footer_left, footer_center, footer_right;

// 	QAtomicInt loading; //Keep track of the numer of pages loading
// 	QVector<QString> temp;
// 	QMap<QString, ArgHandler *> longToHandler; //Map from the long name of an argument, to its handler
// 	QMap<char, ArgHandler *> shortToHandler; //Map form the short switch of an argument, to its handlr

// 	QString html_header;
// 	QString html_footer;

// 	int currentPage;
// 	int pageNum;
// 	int loginTry;

// 	QAtomicInt headerFooterLoading;
// 	QPainter * painter;

// 	QHash<int, QHash<QString, QWebElement> > anchors;
// 	QHash<int, QVector< QPair<QWebElement,QString> > > localLinks;
// 	QHash<int, QVector< QPair<QWebElement,QString> > > externalLinks;
// 	int logicalPages;
// 	int actualPages;
// 	QList<int> pageCount;
// 	QHash<int, QMap< QPair<int, QPair<qreal,qreal> >, QWebElement> > headings;
// 	int tocPages;

	
// 	int networkError;
// #ifdef  __EXTENSIVE_WKHTMLTOPDF_QT_HACK__
// 	TocPrinter tocPrinter;
// #endif

	
// 	QHash<QString, QString> calculateHeaderFooterParams(int document, int page);
// 	QWebPage * loadHeaderFooter(QString url, int document, int page);


// 	//Add a new argument to the list of handled arguments
// 	void addarg(QString l, char s, QString desc, ArgHandler * h, bool display=true);

// 	WKHtmlToPdf(); //Setup stuff not depending on X
// 	QString hfreplace(const QString & q);
// 	QPair<qreal, QPrinter::Unit> parseUnitReal(const char * o);
// 	static QUrl guessUrlFromString(const QString &string);
// 	void version(FILE * fd); //Print version information to fd
// 	void usage(FILE * fd); //Print usage information to fd
// 	bool setPageSize(const char * size);
// 	bool setOrientation(const char * orientation);
// 	bool setProxy(const char * proxy); //parse proxy configuartion
// 	void parseArgs(int argc, const char** argv); //Prase arguments
// 	void init(); //Setup stuff that depends on x
// 	void run(int argc, const char** argv);
// 	void loadDefaults();
// 	void initArgs();
// public slots:
// //	void newPage(QPrinter * p, int fromPage, int toPage, int page);
// 	void amfinished( QNetworkReply * r );
// 	void loadFinished(bool ok);
// 	void loadProgress(int progress);
// 	void sslErrors(QNetworkReply *reply, const QList<QSslError> &error);
// 	void authenticationRequired(QNetworkReply *     , QAuthenticator *);
// 	void printPage();
// 	void preparePrint();


// //	void headerFooterLoadStarted();
// 	void headerFooterLoadFinished(bool ok);

// 	void loadStarted();
// 	void resetPages();
// };
#endif //__wkhtmltopdf_hh__
