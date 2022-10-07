type todo = {
  index: int,
  name: string,
  isCompleted: bool
};

type state = {
  newTodo: string,
  todos: list(todo)
};

type action =
  | AddTodo
  | DeleteTodo(int)
  | MarkTodoAsCompleted(int)
  | ClearTodos;

let initialState = {
  newTodo: "",
  todos: []
};

let reducer = (state, action) => {
  switch (action) {
  | AddTodo => {todos: [{ 
    index: List.length(state.todos), 
    name: state.newTodo, 
    isCompleted: false 
  }, ...state.todos], newTodo: ""}
  | DeleteTodo(index) => {todos: List.filter((todo) => todo.index !== index, state.todos), newTodo: state.newTodo}
  | MarkTodoAsCompleted(index) => {todos: List.map((todo) => todo.index === index ? { ...todo, isCompleted: !todo.isCompleted } : todo, state.todos), newTodo: state.newTodo}
  | ClearTodos => { newTodo: "", todos: [] }
  };
};

[@react.component]
let make = () => {
  <>
    <header><h1>{React.string("ReasonReact Todo Application")}</h1></header>
    <main>
      <AddTodo />
      <Todos />
      <Todo />
    </main>
    <footer><span>{React.string("&copy; 2022")}</span></footer>
  </>;
};
