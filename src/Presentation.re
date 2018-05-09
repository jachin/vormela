let str = ReasonReact.stringToElement;

type route =
  | Slide(option(int));

type state = {
  route,
  previousSlideIndex: int,
  slideIndex: int,
  nextSlideIndex: int
};

type action =
  | ChangeRoute(route);

let calcNextSlide = (i:int) => {
  Js.log(string_of_int(Array.length(Slides.mySlideDeck)));
  if (i >= Array.length(Slides.mySlideDeck)) {
    i;
  }
  else {
    i + 1;
  }
};

let calcPreviouslide = (i:int) => {
  if (i <= 0) {
    i;
  }
  else {
    i - 1;
  }
};

let reducer = (action, state) =>
  switch action {
  | Slide(s) => ReasonReact.Update({
      ...state,
      slideIndex: switch (s) {
      | None => 0
      | Some(s) => s
      }
    })
  };

let mapUrlToRoute = (url: ReasonReact.Router.url) => {
  Js.log("mapUrlToRoute");
  switch url.hash {
  | "" => Slide(Some(0))
  | id => Slide(Some(int_of_string(id)))
  };
};

let currentSlide = (slideIndex) =>
    Slides.mySlideDeck[slideIndex];

let component = ReasonReact.reducerComponent("Presentation");

let getInitialRoute = () => {
  switch (ReasonReact.Router.dangerouslyGetInitialUrl().hash) {
  | "" => 0
  | _ => int_of_string(ReasonReact.Router.dangerouslyGetInitialUrl().hash);
  }
};

let make = (_children) => {
  ...component,
  reducer,
  initialState: () => {route: Slide(Some(getInitialRoute())), slideIndex: 0, previousSlideIndex: 0, nextSlideIndex: 1},
  subscriptions: (self) => [
    Sub(
      () => ReasonReact.Router.watchUrl((url) =>
        self.send(Slide(Some(int_of_string(url.hash))))
      ),
      ReasonReact.Router.unwatchUrl
    )
  ],
  render: (self) =>
    <div>
      (
        switch (self.state.slideIndex) {
        | slideIndex =>
          <div>
            (currentSlide(slideIndex))
            <Previous slide=(self.state.previousSlideIndex) />
            <Next slide=(self.state.nextSlideIndex) />
          </div>
        }
      )
    </div>
};
