open Types

[@react.component]
let make = (~state,~onRemove, ~onIsCompleteToggle, ~completed, ~todosLength) => {
  <>
    <h4>{React.string(string_of_int(completed) ++ " tasks completed out of " ++ string_of_int(todosLength))}</h4>
    <ul className="list-todos">
      (ReasonReact.array(
        Array.of_list(
          List.map((todo: todo) =>
            <TodoItem
              key=(string_of_int(todo.index))
              todo={todo}
              onRemove=((index) => onRemove(index))
              onIsCompleteToggle=((index) => onIsCompleteToggle(index))
            />,
            List.length(state.filteredTodos) > 0 ? state.filteredTodos : state.todos,
          ),
        ),
      ))
    </ul>
  </>
};
