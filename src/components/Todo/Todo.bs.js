'use strict';

var React = require("react");

function Todo(Props) {
  return React.createElement("div", undefined, "Todo: ");
}

var make = Todo;

exports.make = make;
/* react Not a pure module */
