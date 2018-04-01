const HtmlWebpackPlugin = require('html-webpack-plugin')

const { resolve, join } = require('path')
const outputDir = join(__dirname, 'build/')

module.exports = {
  entry: './src/Index.bs.js',
  output: {
    path: outputDir,
    publicPath: outputDir,
    filename: 'Index.js'
  },
  devServer: {
    overlay: true
  },
  plugins: [
    new HtmlWebpackPlugin({
      title: 'Vormela',
      template: resolve('src', 'index.ejs')
    })
  ]
}
