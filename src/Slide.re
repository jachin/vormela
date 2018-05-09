let component = ReasonReact.statelessComponent("Slide");

let make = (~router, _children) => {
  ...component,
  render: (_self) => {
    let gotoHome = (event) => {
      ReactEventRe.Mouse.preventDefault(event);
      DirectorRe.setRoute(router, "/")
    };
    <div>
      <h1>{ReasonReact.stringToElement("Slide")}</h1>
      <a href="#" onClick=gotoHome>{ReasonReact.stringToElement("Home")}</a>
    </div>
  }
};
