'use strict';

var React = require("react");

function AddTodo(Props) {
  return React.createElement("div", undefined, "Add Todo: ");
}

var make = AddTodo;

exports.make = make;
/* react Not a pure module */
