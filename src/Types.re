type todo = {
  index: int,
  name: string,
  isCompleted: bool
};

type state = {
  newTodo: string,
  todos: list(todo),
  filteredTodos: list(todo)
};