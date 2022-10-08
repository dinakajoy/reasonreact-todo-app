'use strict';

var List = require("bs-platform/lib/js/list.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var State$ReasonreactTodoApp = require("./State.bs.js");
var Header$ReasonreactTodoApp = require("./components/Header/Header.bs.js");
var AddTodo$ReasonreactTodoApp = require("./components/AddTodo/AddTodo.bs.js");
var ListTodos$ReasonreactTodoApp = require("./components/ListTodos/ListTodos.bs.js");
var TodoActions$ReasonreactTodoApp = require("./components/TodoActions/TodoActions.bs.js");

require("./styles/global.css");

function App(Props) {
  var match = React.useReducer(State$ReasonreactTodoApp.reducer, State$ReasonreactTodoApp.initialState);
  var dispatch = match[1];
  var state = match[0];
  return React.createElement(React.Fragment, undefined, React.createElement(Header$ReasonreactTodoApp.make, {}), React.createElement("main", undefined, React.createElement(TodoActions$ReasonreactTodoApp.make, {
                      showAllTodos: (function (param) {
                          return Curry._1(dispatch, /* ShowAllTodos */1);
                        }),
                      showCompletedTodos: (function (param) {
                          return Curry._1(dispatch, /* ShowCompletedTodos */2);
                        }),
                      showUncompletedTodos: (function (param) {
                          return Curry._1(dispatch, /* ShowUncompletedTodos */3);
                        }),
                      clearCompletedTodos: (function (param) {
                          return Curry._1(dispatch, /* ClearCompletedTodos */4);
                        }),
                      clearTodos: (function (param) {
                          return Curry._1(dispatch, /* ClearTodos */5);
                        })
                    }), React.createElement(AddTodo$ReasonreactTodoApp.make, {
                      handleChange: (function (name) {
                          return Curry._1(dispatch, {
                                      TAG: /* SetNewTodo */0,
                                      _0: name
                                    });
                        }),
                      todoName: state.newTodo,
                      saveTodo: (function (param) {
                          return Curry._1(dispatch, /* AddTodo */0);
                        })
                    }), React.createElement(ListTodos$ReasonreactTodoApp.make, {
                      state: state,
                      onRemove: (function (index) {
                          return Curry._1(dispatch, {
                                      TAG: /* DeleteTodo */1,
                                      _0: index
                                    });
                        }),
                      onIsCompleteToggle: (function (index) {
                          return Curry._1(dispatch, {
                                      TAG: /* ToggleMarkTodoAsCompleted */2,
                                      _0: index
                                    });
                        }),
                      completed: List.length(List.filter(function (todo) {
                                  return todo.isCompleted === true;
                                })(state.todos)),
                      todosLength: List.length(state.todos)
                    })));
}

var make = App;

exports.make = make;
/*  Not a pure module */
