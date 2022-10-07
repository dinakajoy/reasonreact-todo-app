const path = require('path');
const HtmlWebpackPlugin = require('html-webpack-plugin');
const outputDir = path.join(__dirname, 'build/');

module.exports = {
  entry: './src/Index.bs.js',
  mode: process.env.NODE_ENV === 'production' ? 'production' : 'development',
  output: {
    path: outputDir,
    filename: 'index.js',
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: 'src/index.html',
      inject: false,
    }),
  ],
  devServer: {
    static: {
      directory: outputDir,
    },
    compress: true,
    port: process.env.PORT || 8000,
    historyApiFallback: true,
  },
  module: {
    rules: [
      {
        test: /\.css$/,
        use: [
          { loader: 'style-loader' },
          {
            loader: 'css-loader',
            options: {
              sourceMap: true,
            },
          },
        ],
      },
    ],
  },
};
