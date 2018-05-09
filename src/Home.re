let component = ReasonReact.statelessComponent("Home");

let make = (~router, _children) => {
  ...component,
  render: (_self) => {
    let gotoSlide = (event) => {
      ReactEventRe.Mouse.preventDefault(event);
      DirectorRe.setRoute(router, "/side")
    };
    <div>
      <h1>{ReasonReact.string("Home")}</h1>
      <a href="#" onClick=gotoSlide>{ReasonReact.string("Slide")}</a>
    </div>
  }
};
