open Types
open State

[@bs.val] external requireCSS: string => unit = "require";
requireCSS("./styles/global.css");

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  <>
    <Header />
    <main>
      <TodoActions 
        showAllTodos={() => dispatch(ShowAllTodos)} 
        showCompletedTodos={() => dispatch(ShowCompletedTodos)}
        showUncompletedTodos={() => dispatch(ShowUncompletedTodos)} 
        clearCompletedTodos={() => dispatch(ClearCompletedTodos)} 
        clearTodos={() => dispatch(ClearTodos)} 
      />
      <AddTodo 
        handleChange={(name) => dispatch(SetNewTodo(name))} 
        todoName={state.newTodo} 
        saveTodo=(() => dispatch(AddTodo)) 
      />
      <ListTodos 
        state={state} 
        onRemove=((index) => dispatch(DeleteTodo(index)))
        onIsCompleteToggle=((index) => dispatch(ToggleMarkTodoAsCompleted(index)))
        todosLength={List.length(state.todos)}
        completed={List.length(List.filter((todo) => todo.isCompleted === true, state.todos))}
      />
    </main>
  </>;
};
