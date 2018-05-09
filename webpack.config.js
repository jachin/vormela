const HtmlWebpackPlugin = require('html-webpack-plugin')
const HtmlWebpackHarddiskPlugin = require('html-webpack-harddisk-plugin')
const MiniCssExtractPlugin = require('mini-css-extract-plugin')

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
      template: resolve('src', 'index.ejs'),
      alwaysWriteToDisk: true
    }),
    new HtmlWebpackHarddiskPlugin(),
    new MiniCssExtractPlugin({
      filename: '[name].css',
      chunkFilename: '[id].css'
    })
  ],
  module: {
    rules: [{
      test: /\.css$/,
      use: [
        MiniCssExtractPlugin.loader,
        'css-loader'
      ]
    }]
  }
}
