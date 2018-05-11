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
<div className="slide"><h1>(str("Reason"))</h1>
<p>(str("Ocaml that gets complied into javascript."))</p>
<p>(str("BuckleScript - Compiles OCaml &amp; Reason to JavaScript"))</p></div>,
<div className="slide"><h1>(str("ReasonReact"))</h1>
<p>(str("Reason with React"))</p>
<div className="codehilite"><pre><span></span><span className="k">(str("let"))</span> <span className="n">(str("component"))</span> <span className="o">(str("="))</span> <span className="nn">(str("ReasonReact"))</span><span className="p">(str("."))</span><span className="n">(str("statelessComponent"))</span><span className="o">(str("("))</span><span className="s2">(str("\"Greeting\""))</span><span className="o">(str(");"))</span>

<span className="k">(str("let"))</span> <span className="n">(str("make"))</span> <span className="o">(str("="))</span> <span className="o">(str("(~"))</span><span className="n">(str("name"))</span><span className="o">(str(","))</span> <span className="o">(str("_"))</span><span className="n">(str("children"))</span><span className="o">(str(")"))</span> <span className="o">(str("=&gt;"))</span> <span className="o">(str("{"))</span>
  <span className="o">(str("..."))</span><span className="n">(str("component"))</span><span className="o">(str(","))</span>
  <span className="n">(str("render"))</span><span className="o">(str(":"))</span> <span className="o">(str("_"))</span><span className="n">(str("self"))</span> <span className="o">(str("=&gt;"))</span>
    <span className="o">(str("&lt;"))</span><span className="n">(str("button"))</span><span className="o">(str("&gt;"))</span>
      <span className="o">(str("{"))</span><span className="nn">(str("ReasonReact"))</span><span className="p">(str("."))</span><span className="n">(str("string"))</span><span className="o">(str("("))</span><span className="s2">(str("\"Hello!\""))</span><span className="o">(str(")}"))</span>
    <span className="o">(str("&lt;/"))</span><span className="n">(str("button"))</span><span className="o">(str("&gt;"))</span>
<span className="o">(str("};"))</span>
</pre></div></div>,
<div className="slide"><p>(str("https://github.com/jachin/vormela"))</p>
<p>(str("https://github.com/vramana/awesome-reasonml"))</p></div>
];
