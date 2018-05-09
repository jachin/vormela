let str = ReasonReact.string;
let mySlideDeck = Slides.mySlideDeck;

type state = {
  currentSlideIndex: int,
  slides: list(ReasonReact.reactElement),
};

type action =
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
  | NextSlide => ReasonReact.Update({...state, currentSlideIndex: state.currentSlideIndex + 1})
  | PreviousSlide => ReasonReact.Update({...state, currentSlideIndex: state.currentSlideIndex - 1})
  };

let component = ReasonReact.reducerComponent("Presentation");

let make = (_children) => {
  ...component,
  reducer,
  initialState: () => {currentSlideIndex: 0, slides: Slides.mySlideDeck},
  render: (self) =>
    <div>
      (getCurrentSlide(~index=self.state.currentSlideIndex, self.state.slides))
    </div>
};
