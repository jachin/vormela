let str = ReasonReact.stringToElement;

let mySlideDeck = [|
  <div className="slide"><h1>(str("Reason"))</h1>
<h2>(str("A Slide Deck"))</h2>
<p>(str("So much more work that I thought it would be."))</p></div>,
<div className="slide"><h1>(str("Ocaml"))</h1>
<h3>(str("Turns Out..."))</h3>
<h2>(str("The 'ml' is NOT for \"Mark Down\""))</h2></div>,
<div className="slide"><h1>(str("Reason"))</h1>
<p>(str("Ocaml that gets complied into javascript."))</p></div>,
<div className="slide"><p>(str("https://github.com/jachin/vormela"))</p>
<p>(str("https://github.com/vramana/awesome-reasonml"))</p></div>
|];
