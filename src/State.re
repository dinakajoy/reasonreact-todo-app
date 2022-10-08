open Types

type action =
  | SetNewTodo(string)
  | AddTodo
  | DeleteTodo(int)
  | ToggleMarkTodoAsCompleted(int)
  | ShowAllTodos
  | ShowCompletedTodos
  | ShowUncompletedTodos
  | ClearCompletedTodos
  | ClearTodos;

let initialState = {
  newTodo: "",
  todos: [
    {
      index: 0,
      name: "Complete a Reason project by Friday evening",
      isCompleted: false
    },
    {
      index: 1,
      name: "Complete my current ReScript project by Saturday night",
      isCompleted: false
    }
  ],
  filteredTodos: []
};

let reducer = (state, action) => {
  switch (action) {
  | SetNewTodo(name) => { ...state, newTodo: name }
  | AddTodo => {
      todos: [
        { 
          index: List.length(state.todos), 
          name: state.newTodo, 
          isCompleted: false 
        }, 
        ...state.todos
      ], 
      newTodo: "", 
      filteredTodos: [] 
    }
  | DeleteTodo(index) => { 
      todos: List.filter((todo) => todo.index !== index, state.todos),
      newTodo: state.newTodo, 
      filteredTodos: []
    }
  | ToggleMarkTodoAsCompleted(index) => {
      todos: List.map((todo) => todo.index === index ? { ...todo, isCompleted: !todo.isCompleted } : todo, state.todos),
      newTodo: state.newTodo, 
      filteredTodos: []
    }
  | ClearCompletedTodos => {
      newTodo: state.newTodo, 
      filteredTodos: [], 
      todos: List.filter((todo) => todo.isCompleted !== true, state.todos),
    }
  | ShowAllTodos => {
      ...state, 
      filteredTodos: [],
    }
  | ShowCompletedTodos => {
      filteredTodos: List.filter((todo) => todo.isCompleted === true, state.todos),
      newTodo: state.newTodo, 
      todos: state.todos
    }
  | ShowUncompletedTodos => {
      newTodo: state.newTodo, 
      todos: state.todos,
      filteredTodos: List.filter((todo) => todo.isCompleted !== true, state.todos)
    }
  | ClearTodos => { newTodo: "", todos: [], filteredTodos: [] }
  };
};