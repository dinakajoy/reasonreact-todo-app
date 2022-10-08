'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");

function AddTodo(Props) {
  var handleChange = Props.handleChange;
  var todoName = Props.todoName;
  var saveTodo = Props.saveTodo;
  return React.createElement("div", {
              className: "add-container"
            }, React.createElement("input", {
                  type: "text",
                  value: todoName,
                  onChange: (function ($$event) {
                      return Curry._1(handleChange, $$event.target.value);
                    })
                }), React.createElement("button", {
                  onClick: (function (_event) {
                      return Curry._1(saveTodo, undefined);
                    })
                }, "Add Todo"));
}

var make = AddTodo;

exports.make = make;
/* react Not a pure module */
