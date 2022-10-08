[@react.component]
let make = (~showAllTodos, ~showCompletedTodos, ~showUncompletedTodos, ~clearCompletedTodos, ~clearTodos) => {
  <div className="todo-actions-wrapper">
    <button className="all-todos-button" onClick={_event => showAllTodos()}>
      {React.string("All Todos")}
    </button>
    <button className="show-comp-todos-button" onClick={_event => showCompletedTodos()}>
      {React.string("Completed Todos")}
    </button>
    <button className="show-uncomp-todos-button" onClick={_event => showUncompletedTodos()}>
      {React.string("UnCompleted Todos")}
    </button>
    <button className="clear-comp-todos-button" onClick={_event => clearCompletedTodos()}>
      {React.string("Clear Completed Todos")}
    </button>
    <button className="clear-all-todos-button" onClick={(_) => clearTodos()}>
      {React.string("Clear Todos")}
    </button>
  </div>
};