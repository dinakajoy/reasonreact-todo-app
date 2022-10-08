[@react.component]
let make = (~handleChange, ~todoName, ~saveTodo) => {
  <div className="add-container">
    <input
      type_="text"
      value=todoName
      onChange={event => {
        let value = ReactEvent.Form.target(event)##value;
        handleChange(value);
      }}
    />
    <button onClick={_event => saveTodo()}>{React.string("Add Todo")}</button>
  </div>
};