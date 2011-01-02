; $Id: activ8.make,v 1.5-dev 2010/12/18 14:54:04 zfactor Exp $
core = "6.x"

; drush make file

core = 6.x

projects[] = "drupal"

;contrib modules

projects[addthis][subdir] = "contrib"
projects[addthis][version] = 2.9

projects[admin][subdir] = "contrib"
projects[admin][version] = 2.0-rc1

projects[advanced_help][subdir] = "contrib"
projects[advanced_help][version] = 1.2

projects[auto_nodetitle][subdir] = "contrib"
projects[auto_nodetitle][version] = 1.2

projects[captcha][subdir] = "contrib"
projects[captcha][version] = 2.2

projects[cck][subdir] = "contrib"
projects[cck][version] = 2.8

projects[ckeditor][subdir] = "contrib"
projects[ckeditor][version] = 1.1

projects[content_complete][subdir] = "contrib"
projects[content_complete][version] = 1.3

projects[content_profile][subdir] = "contrib"
projects[content_profile][version] = 1.0

;projects[context][subdir] = "contrib"
;projects[context][version] = 3.0-rc1

projects[ctools][subdir] = "contrib"
projects[ctools][version] = 1.7

projects[date][subdir] = "contrib/date"
projects[date][version] = 2.6

projects[devel][subdir] = "contrib"
projects[devel][version] = 1.23

projects[diff][subdir] = "contrib"
projects[diff][version] = 2.1

projects[disqus][subdir] = "contrib"
projects[disqus][version] = 1.6

projects[distro][subdir] = "contrib"
projects[distro][version] = 1.0-rc1

projects[draggableviews][subdir] = "contrib"
projects[draggableviews][version] = 3.4

projects[editablefields][subdir] = "contrib"
projects[editablefields][version] = 2.0

projects[email][subdir] = "contrib"
projects[email][version] = 1.2

projects[features][subdir] = "contrib"
projects[features][version] = 1.0-rc1

projects[feeds][subdir] = "contrib"
projects[feeds][version] = 1.0-beta4

projects[filefield][subdir] = "contrib"
projects[filefield][version] = 3.7

projects[flag][subdir] = "contrib"
projects[flag][version] = 2.0-beta3

projects[flot][subdir] = "contrib"
projects[flot][version] = 1.2

projects[fullcalendar][subdir] = "contrib"
projects[fullcalendar][version] = 1.2-beta6

projects[getid3][subdir] = "contrib"
projects[getid3][version] = 1.4

projects[globalredirect][subdir] = "contrib"
projects[globalredirect][version] = 1.2

projects[google_analytics][subdir] = "contrib"
projects[google_analytics][version] = 2.2

projects[google_fonts][subdir] = "contrib"
projects[google_fonts][version] = 1.6

projects[imageapi][subdir] = "contrib"
projects[imageapi][version] = 1.8

projects[imagecache][subdir] = "contrib"
projects[imagecache][version] = 2.0-beta10

projects[imagefield][subdir] = "contrib"
projects[imagefield][version] = 3.7

projects[imagefield_crop][subdir] = "contrib"
projects[imagefield_crop][version] = 1.0-rc2

projects[imce][subdir] = "contrib"
projects[imce][version] = 2.1

projects[job_scheduler][subdir] = "contrib"
projects[job_scheduler][version] = 1.0-beta3

projects[jquery_ui][subdir] = "contrib"
projects[jquery_ui][version] = 1.3

projects[jquery_update][subdir] = "contrib"
projects[jquery_update][version] = 2.0-alpha1

projects[libraries][subdir] = "contrib"
projects[libraries][version] = 1.0-alpha1

projects[link][subdir] = "contrib"
projects[link][version] = 2.9

projects[location][subdir] = "contrib"
projects[location][version] = 3.1

projects[nodewords][subdir] = "contrib"
projects[nodewords][version] = 1.12-beta9

projects[openlayers][subdir] = "contrib"
projects[openlayers][version] = 2.0-alpha8

projects[page_title][subdir] = "contrib"
projects[page_title][version] = 2.3

projects[path_redirect][subdir] = "contrib"
projects[path_redirect][version] = 1.0-beta7

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = 2.0-alpha2

projects[phone][subdir] = "contrib"
projects[phone][version] = 2.17

projects[print][subdir] = "contrib"
projects[print][version] = 1.11

projects[realname][subdir] = "contrib"
projects[realname][version] = 1.3

projects[recaptcha][subdir] = "contrib"
projects[recaptcha][version] = 1.4

projects[rules][subdir] = "contrib/rules"
projects[rules][version] = 1.2

projects[scheduler][subdir] = "contrib"
projects[scheduler][version] = 1.7

projects[scribdfield][subdir] = "contrib"
projects[scribdfield][version] = 1.0

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = 2.0

projects[styles][subdir] = "contrib"
projects[styles][version] = 2.0-alpha5

projects[tagging][subdir] = "contrib"
projects[tagging][version] = 2.5

projects[token][subdir] = "contrib"
projects[token][version] = 1.14

projects[vertical_tabs][subdir] = "contrib"
projects[vertical_tabs][version] = 1.0-rc1

projects[views][subdir] = "contrib"
projects[views][version] = 3.0-alpha3

projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = 1.9

projects[votingapi][subdir] = "contrib"
projects[votingapi][version] = 2.3

projects[webform][subdir] = "contrib"
projects[webform][version] = 3.4

projects[xmlsitemap][subdir] = "contrib"
projects[xmlsitemap][version] = 2.0-beta1

; module in dev version


projects[emfield][subdir] = "contrib"
projects[emfield][type] = "module"
projects[emfield][download][type] = "cvs"
projects[emfield][download][module] = "contributions/modules/emfield"
projects[emfield][download][revision] = "DRUPAL-6--2:2010-08-07"

; Themes
projects[] = "rubik"
projects[] = "tao"
projects[] = "fusion"

; active8 features are hosted in a private repository for now
; if saved somewhere online as tarballs, they can be downloaded using
; the following syntax:
; projects[feature_name][type] = "module"
; project[feature_name][download][type] = "get"
; project[feature_name][download][url] = "http://mysite.com/feature_name.zip | tar.gz"
; project[feature_name][subdir] = "activ8/activ8_features"


projects[activ8_blog][subdir] = "activ8/activ8_features"
projects[activ8_blog][type] = "module"
projects[activ8_blog][download][type] = "svn"
projects[activ8_blog][download][username] = "activ8"
projects[activ8_blog][download][password] = "activ8"
projects[activ8_blog][download][url] = "http://activ8.unfuddle.com/svn/activ8_activ8features/trunk/activ8_blog/"

projects[activ8_document_library][subdir] = "activ8/activ8_features"
projects[activ8_document_library][type] = "module"
projects[activ8_document_library][download][type] = "svn"
projects[activ8_document_library][download][username] = "activ8"
projects[activ8_document_library][download][password] = "activ8"
projects[activ8_document_library][download][url] = "http://activ8.unfuddle.com/svn/activ8_activ8features/trunk/activ8_document_library/"

projects[activ8_event_calendar][subdir] = "activ8/activ8_features"
projects[activ8_event_calendar][type] = "module"
projects[activ8_event_calendar][download][type] = "svn"
projects[activ8_event_calendar][download][username] = "activ8"
projects[activ8_event_calendar][download][password] = "activ8"
projects[activ8_event_calendar][download][url] = "http://activ8.unfuddle.com/svn/activ8_activ8features/trunk/activ8_event_calendar/"

projects[activ8_homepage_slideshow][subdir] = "activ8/activ8_features"
projects[activ8_homepage_slideshow][type] = "module"
projects[activ8_homepage_slideshow][download][type] = "svn"
projects[activ8_homepage_slideshow][download][username] = "activ8"
projects[activ8_homepage_slideshow][download][password] = "activ8"
projects[activ8_homepage_slideshow][download][url] = "http://activ8.unfuddle.com/svn/activ8_activ8features/trunk/activ8_homepage_slideshow/"

; the active8 installation profile
;projects[activ8][type] = "profile"
;projects[activ8][download][type] = "svn"
;projects[activ8][download][username] = "activ8"
;projects[activ8][download][password] = "activ8"
;projects[activ8][download][url] = "http://activ8.unfuddle.com/svn/activ8_activ8/trunk/"

;Libraries
; ckeditor 3.3.2
libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.3.2/ckeditor_3.3.2.zip"
libraries[ckeditor][directory_name] = "ckeditor"

; getid3()
libraries[getid3][download][type] = "get"
libraries[getid3][download][url] = "http://downloads.sourceforge.net/project/getid3/getID3%28%29%201.x/1.7.9/getid3-1.7.9.zip"
libraries[getid3][directory_name] = "getid3"

http://downloads.sourceforge.net/project/getid3/getID3%28%29%201.x/1.7.9/getid3-1.7.9.zip

; jQuery UI
libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery-ui-1.7.2.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"
libraries[jquery_ui][destination] = "modules/contrib/jquery_ui"



