#pragma once
#include "memory.h"

/****
* // from http://www.rforge.net/audio/

* typedef struct audio_driver {
*   unsigned int length; // length of the driver structure, i.e., sizeof(audio_driver_t)
*   const char *name; // short identifier
*   const char *descr; // description
*   const char *copyright; // copyright (optional)
*
*   struct audio_instance *(*create_player)(SEXP source, float rate, int flags);
*   struct audio_instance *(*create_recorder)(SEXP target, float rate, int channels, int flags); /* (optional)
*   int (*start)(struct audio_instance *); // start recording/playback
*   int (*pause)(struct audio_instance *); // pause recording/playback
*   int (*resume)(struct audio_instance *); // resume previously paused recording/playback
*   int (*rewind)(struct audio_instance *); // move the pointer in the source/target to the beginning
*   int (*wait)(struct audio_instance *, double timeout); // Note: the instance may be NULL for global wait
*   int (*close)(struct audio_instance *); // close the instance, may release underlying audio objects
*   void (*dispose)(struct audio_instance *); // must free the instance pointer and all internally allocated memory/objects
* } audio_driver_t;
*/
	
//typedef struct book{
//	unsigned int id;
//	char* name;
//	char* content;
//	//void (*book_t_free)(book_t* self);
//	//void (*book_t_read)();
//	//void (*read)(struct book* self);
//} book_t;


// struct input_plugin_curl_userdata {
//     strbuf url;
//     strbuf buffer;
//     strbuf tmp;
//     taglist tags;
//     CURL* handle;
//     CURLM* mhandle;
//     struct curl_slist* headers;
//     unsigned int connect_timeout;
//     unsigned int read_timeout;
//     unsigned int ignore_icecast;
//     int tags_sent;
//     int icy_header;
//     unsigned int metaint;
//     unsigned int metaread;
//     unsigned int in_headers;
//     long verbose;
//     size_t (read)(struct input_plugin_curl_userdata, void*, size_t, const tag_handler*, unsigned int timeout);
// };

// typedef struct input_plugin_curl_userdata input_plugin_curl_userdata;


struct book {
	unsigned int id;
	char* name;
	char* content;

	unsigned int read_count;

	void (*read)(struct book* self);
};

struct book* book_new(void);
void book_free(struct book* book);
