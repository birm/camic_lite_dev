var sharp = require('sharp');

sharp('sample.svs').tile(256).toFile('output.dzi', function(err, info) {
  // The output.dzi file is the XML format Deep Zoom definition
  // The output_files directory contains 256x256 pixel tiles grouped by zoom level
});
