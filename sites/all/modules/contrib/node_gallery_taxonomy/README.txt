$Id: README.txt,v 1.1.2.1 2010/12/22 23:04:16 justintime Exp $

Summary
-------

Node Gallery Taxonomy is a module designed to work with Node Gallery by
providing one very specific feature: the cascading of taxonomy from a gallery
node down to the image nodes upon modification.

Installation
------------
 * Copy the module file to your modules directory, extract it, and enable it at
/admin/build/modules.
 
 * Visit your Node Gallery Relationships at admin/settings/node_gallery/list and
click "Change Settings" on each relationship you wish to enable taxonomy
cascading on.

 * Check the box labeled "Enable taxonomy cascade from gallery to images?" and
press save.

 * When you have your gallery taxonomy set the way you want, revisit the settings
and click the button labeled "One-time sync of taxonomy...".  This will perform
an initial sync of all taxonomy terms from the galleries to their images.
 
From here on out, any time you change the taxonomy on a gallery, it will cascade
down to the image nodes. 