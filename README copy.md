# Country_Select

This is a ReasonReact project that allows users to chose countries from a custom dropdown list of countries. Users can use the `Tab` key to navigate through the content and the `Enter` or `Space Bar` key to select an item and close the dropdown 

## Project Structure

All the main project files can be found in the `src` folder  
- Index.html: The single HTML file we need to render our single page app on the browser
- Index.re: This is the entry point of this application
- App.re: App puts together all components to render this application
- Utils.re: This contains utility functions that might be reused in several components
- Types.re: This contains all the types/interfaces for his application
- assets: contains project assets such as images
- components: contains reusable components in our application 
- styles: contains a global css file that styles the full application

`Note:` A global style was used here because this is a one page small application. You can use CSS modules if you are going to have many compnents and pages in your application

## How to run this application

```sh
npm install or yarn install
npm run server or yarn run server
# in a new tab
npm start or yarn start
```

## How to use and modify this application

Open a new web page to `http://localhost:8000/`. Change any `.re` file in `src` to see the page auto-reload.
