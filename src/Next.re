let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Next");

let handleClick = (nextSlide, event) =>
  if (! ReactEventRe.Mouse.defaultPrevented(event)) {
    ReactEventRe.Mouse.preventDefault(event);
    ReasonReact.Router.push("/slide/" ++ string_of_int(nextSlide))
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
      "href": "/slide/" ++ string_of_int(slide + 1),
      "onClick": handleClick(slide + 1),
      "onKeyUp": handleKeyUp(slide + 1)
    },
    [| (str("Next")) |]
  )
};
