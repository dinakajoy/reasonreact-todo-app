let headerStyle = ReactDOMRe.Style.make(~height="15vh", ~marginBottom="20px", ~display="flex", ~alignItems="center", ~justifyContent="center", ~textAlign="center", ~backgroundColor="#000", ~color="#fff", ());

let hOneStyle = ReactDOMRe.Style.make(~fontSize="2rem", ());

[@react.component]
let make = () => {
  <header style=headerStyle>
    <h1 style=hOneStyle>{React.string("ReasonReact Todo Application")}</h1>
  </header>
};
