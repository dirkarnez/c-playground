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
	
typedef_entity_struct(book, struct {
	char* name;
	char* content;
});

book* book_new(void);
void book_free(book* self);
void book_read(book* self);
