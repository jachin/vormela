let component = ReasonReact.statelessComponent("Home");

let make = (~router, _children) => {
  ...component,
  render: (_self) => {
    let gotoSlide = (event) => {
      ReactEventRe.Mouse.preventDefault(event);
      DirectorRe.setRoute(router, "/side")
    };
    <div>
      <h1>{ReasonReact.stringToElement("Home")}</h1>
      <a href="#" onClick=gotoSlide>{ReasonReact.stringToElement("Slide")}</a>
    </div>
  }
};
