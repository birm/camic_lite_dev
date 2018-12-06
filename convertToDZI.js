var sharp = require('sharp');

function convertToDZI(input, output, callback){
  return sharp(input).limitInputPixels(false).tile(255).toFile(output, function(err, info) {
    callback(err, info)
  });
}

module.exports = convertToDZI
