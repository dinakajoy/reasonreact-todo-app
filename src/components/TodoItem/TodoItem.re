open Types

[@react.component]
let make = (~todo, ~onRemove, ~onIsCompleteToggle) => {
  <li>
    <input
      type_="checkbox"
      checked={todo.isCompleted}
      onChange={
        _event => {
          onIsCompleteToggle(todo.index)
        }
      }
      title={todo.isCompleted ? "Mark Todo As Uncompleted" : "Mark Todo As Completed"}
    />
    {todo.isCompleted ? <s>{React.string(todo.name)}</s> : {React.string(todo.name)}}
    <span onClick={(_) => onRemove(todo.index)} title="Remove Todo">{React.string("x")}</span>
  </li>
};