let str = ReasonReact.string;

let mySlideDeck = [
  <div className="slide"><h1>(str("Reason"))</h1>
<h2>(str("A Slide Deck"))</h2>
<blockquote>
<p>(str("So much more work that I thought it would be. ----Jachin Rupe circa May 2018"))</p>
</blockquote></div>,
<div className="slide"><h1>(str("Ocaml"))</h1>
<h3>(str("Turns Out..."))</h3>
<h2>(str("The 'ml' is NOT for \"Mark Down\""))</h2></div>,
<div className="slide"><h1>(str("OCaml"))</h1>
<pre>(str("let length list =
    let rec aux n = function
      | [] -> n
      | _::t -> aux (n+1) t
    in aux 0 list;;
"))</pre></div>,
<div className="slide"><h1>(str("OCaml"))</h1>
<ul>
<li>(str("Functional"))</li>
<li>(str("Strongly-Typed"))</li>
<li>(str("Expressive"))</li>
<li>(str("Safe"))</li>
<li>(str("Complied ... But acts like it's interpreted ... utop"))</li>
</ul></div>,
<div className="slide"><h1>(str("$$ OCaml $$"))</h1>
<p>(str("According to the 2018 StackOverflow developer survey OCaml is associated with some of the highest developer salaries."))</p></div>,
<div className="slide"><h1>(str("Reason"))</h1>
<p>(str("Reason's a syntax for OCaml and supports all its features. BuckleScript compiles OCaml/Reason code into JavaScript."))</p>
<p>(str("BuckleScript - Compiles OCaml and Reason to JavaScript"))</p></div>,
<div className="slide"><h1>(str("ReasonReact"))</h1>
<p>(str("Reason with React"))</p>
<pre>(str("let component = ReasonReact.statelessComponent(
  \"Greeting\"
);

let make = (~name, _children) => {
  ...component,
  render: _self =>
    <button>
      {ReasonReact.string(\"Hello!\")}
    </button>
};
"))</pre></div>,
<div className="slide"><h1>(str("This Presentation"))</h1>
<ul>
<li>(str("ReasonReact"))</li>
<li>(str("Webpack 4"))</li>
<li>(str("Python (for cutting corners)"))</li>
</ul></div>,
<div className="slide"><h1>(str("Building"))</h1>
<ul>
<li>(str("Slides are written in markdown."))</li>
</ul>
<h2>(str("deckbuilder.py"))</h2>
<ul>
<li>(str("Python script converts slides into a Reason list of JSX nodes."))</li>
</ul>
<h2>(str("yarn start"))</h2>
<ul>
<li>(str("uses BuckleScript to compile all the Reason files into sibling JS files."))</li>
</ul>
<h2>(str("yarn run webpack"))</h2>
<ul>
<li>(str("finds all the javascript files and packs them into an app."))</li>
<li>(str("browse localhost:8080 and enjoy"))</li>
</ul></div>,
<div className="slide"><h1>(str("Retrospective"))</h1>
<ul>
<li>(str("Steep learning curve"))</li>
<li>(str("First time using an 'ml' programming language"))</li>
<li>(str("First time using a strongly typed language."))</li>
<li>(str("Almost the first time using react."))</li>
</ul></div>,
<div className="slide"><h1>(str("Retrospective"))</h1>
<ul>
<li>(str("Many iterations"))</li>
<li>(str("Many did not work at all"))</li>
<li>(str("Wanted URL routing to work"))</li>
</ul></div>,
<div className="slide"><h1>(str("Retrospective"))</h1>
<h2>(str("Use Reason again for fun?"))</h2>
<blockquote>
<p>(str("Eh, probably not... unless I needed to learn OCaml/Reason for professional reasons."))</p>
</blockquote>
<h2>(str("Use React again for fun?"))</h2>
<blockquote>
<p>(str("Probably, but I need to learn more about react."))</p>
</blockquote></div>,
<div className="slide"><h1>(str("Retrospective?"))</h1>
<h2>(str("Is ReasonReact ready to become Empyrean's primary frontend framework?"))</h2>
<blockquote>
<p>(str("Probably not, the vibe I get is that they are still adding some fairly fundamental stuff."))</p>
<p>(str("Lots of \"escape hatching\" into javascript."))</p>
</blockquote></div>,
<div className="slide"><h1>(str("Links"))</h1>
<h2>(str("Presentation"))</h2>
<p>(str("https://github.com/jachin/vormela"))</p>
<h2>(str("Awesome Reason"))</h2>
<p>(str("https://github.com/vramana/awesome-reasonml"))</p></div>,
<div className="slide"><h1>(str("Thank you"))</h1>
<h3>(str("What's with that name \"vormela\"."))</h3>
<p>(str("A vormela is marbled polecat."))</p>
<h3>(str("Yeah but why is it called that?"))</h3>
<p>(str("Naming things is important but sometimes you do not want to spent too much time on it."))</p>
<p>(str("https://pypi.org/project/randomium/"))</p></div>
];
