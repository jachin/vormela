let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Next");

let handleClick = (nextSlide, event) =>
  if (! ReactEventRe.Mouse.defaultPrevented(event)) {
    ReactEventRe.Mouse.preventDefault(event);
    ReasonReact.Router.push("/#" ++ string_of_int(nextSlide))
  };

let handleKeyUp = (nextSlide, event) => {
  Js.log("Keyup");
  if (ReactEventRe.Keyboard.key(event) === "ArrowRight") {
    Js.log("Right Arrow" ++ string_of_int(nextSlide));
  };
};

let make = (~slide, _children) => {
  ...component,
  render: (_self) => ReasonReact.createDomElement(
    "a",
    ~props={
      "href": "/#" ++ string_of_int(slide),
      "onClick": handleClick(slide),
      "onKeyUp": handleKeyUp(slide),
      "className": "nextButton"
    },
    [| (str("Next")) |]
  )
};
