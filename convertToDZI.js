var sharp = require('sharp');

function convertToDZI(input, output){
  sharp(input).tile(255).toFile(output, function(err, info) {
    // The output.dzi file is the XML format Deep Zoom definition
    // The output_files directory contains 256x256 pixel tiles grouped by zoom level
  });
}

module.exports = convertToDZI
