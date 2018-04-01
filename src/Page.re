let str = ReasonReact.stringToElement;

type route =
  | Slide(int);

type state = {
  route,
};

type action =
  | ChangeRoute(route);

let reducer = (action, _state) =>
  switch action {
  | ChangeRoute(route) => ReasonReact.Update({route: route})
  };

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch url.path {
  | [] => Slide(0)
  | ["slide", id] => Slide(int_of_string(id))
  | _ => Slide(0)
  };

let currentSlide = (slideIndex) =>
    Slides.mySlideDeck[slideIndex];

let component = ReasonReact.reducerComponent("Page");

let make = (_children) => {
  ...component,
  reducer,
  initialState: () => {route: Slide(0)},
  subscriptions: (self) => [
    Sub(
      () => ReasonReact.Router.watchUrl((url) =>
        self.send(ChangeRoute(url |> mapUrlToRoute))
      ),
      ReasonReact.Router.unwatchUrl
    )
  ],
  render: (self) =>
    <div>
      (
        switch (self.state.route) {
        | Slide(slideIndex) =>
          <div>
            (currentSlide(slideIndex))
            <Previous slide=(slideIndex) />
            <Next slide=(slideIndex) />
          </div>
        }
      )
    </div>
};
