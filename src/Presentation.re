let str = ReasonReact.string;
let mySlideDeck = Slides.mySlideDeck;

type state = {
  currentSlideIndex: int,
  slides: list(ReasonReact.reactElement),
};

type action =
  | JumpToSlide(int)
  | NextSlide
  | PreviousSlide;

let rec getCurrentSlide = (~index: int, slides: list(ReasonReact.reactElement)) =>
  switch slides {
    | [] => ReasonReact.string("No slides? That's weird")
    | [head , ..._] when index <= 0 => head
    | [_, ...tail] => getCurrentSlide(~index=index-1, tail)
  };

let reducer = (action, state) =>
  switch action {
  | JumpToSlide(i) => ReasonReact.Update({...state, currentSlideIndex: i})
  | NextSlide => ReasonReact.Update({...state, currentSlideIndex: state.currentSlideIndex + 1})
  | PreviousSlide => ReasonReact.Update({...state, currentSlideIndex: state.currentSlideIndex - 1})
  };

let component = ReasonReact.reducerComponent("Presentation");

let parseUrlHashForSlideIndex = hash => {
  try (int_of_string(hash)) {
    | Failure(_) => 0
  };
};

let make = (_children) => {
  ...component,
  reducer,
  initialState: () => {currentSlideIndex: 0, slides: Slides.mySlideDeck},
  subscriptions: self => [
    Sub(
      () =>
        ReasonReact.Router.watchUrl(url => {
          let newIndex = parseUrlHashForSlideIndex(url.hash);
          Js.log("newIndex " ++ string_of_int(newIndex));
          self.send(JumpToSlide(newIndex));
        }),
        ReasonReact.Router.unwatchUrl
      )
    ],
  render: (self) =>
    <div>
      (getCurrentSlide(~index=self.state.currentSlideIndex, self.state.slides))
      <div>
        <button onClick=(_event => self.send(NextSlide))>
          (ReasonReact.string("Next"))
        </button>
        <button onClick=(_event => self.send(PreviousSlide))>
          (ReasonReact.string("Previous"))
        </button>
      </div>
    </div>
};
