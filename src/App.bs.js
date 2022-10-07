'use strict';

var List = require("bs-platform/lib/js/list.js");
var React = require("react");
var Todo$ReasonreactTodoApp = require("./components/Todo/Todo.bs.js");
var Todos$ReasonreactTodoApp = require("./components/Todos/Todos.bs.js");
var AddTodo$ReasonreactTodoApp = require("./components/AddTodo/AddTodo.bs.js");

function reducer(state, action) {
  if (typeof action === "number") {
    if (action === /* AddTodo */0) {
      return {
              newTodo: "",
              todos: {
                hd: {
                  index: List.length(state.todos),
                  name: state.newTodo,
                  isCompleted: false
                },
                tl: state.todos
              }
            };
    } else {
      return {
              newTodo: "",
              todos: /* [] */0
            };
    }
  }
  if (action.TAG === /* DeleteTodo */0) {
    var index = action._0;
    return {
            newTodo: state.newTodo,
            todos: List.filter(function (todo) {
                    return todo.index !== index;
                  })(state.todos)
          };
  }
  var index$1 = action._0;
  return {
          newTodo: state.newTodo,
          todos: List.map((function (todo) {
                  if (todo.index === index$1) {
                    return {
                            index: todo.index,
                            name: todo.name,
                            isCompleted: !todo.isCompleted
                          };
                  } else {
                    return todo;
                  }
                }), state.todos)
        };
}

function App(Props) {
  return React.createElement(React.Fragment, undefined, React.createElement("header", undefined, React.createElement("h1", undefined, "ReasonReact Todo Application")), React.createElement("main", undefined, React.createElement(AddTodo$ReasonreactTodoApp.make, {}), React.createElement(Todos$ReasonreactTodoApp.make, {}), React.createElement(Todo$ReasonreactTodoApp.make, {})), React.createElement("footer", undefined, React.createElement("span", undefined, "&copy; 2022")));
}

var initialState = {
  newTodo: "",
  todos: /* [] */0
};

var make = App;

exports.initialState = initialState;
exports.reducer = reducer;
exports.make = make;
/* react Not a pure module */
