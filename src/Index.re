
let renderForRoute = (element) =>
  ReactDOMRe.renderToElementWithId(element, "root");

let router = DirectorRe.makeRouter({
  "/": "home",
  "/slide": "slide",
});

let handlers = {
  "home": () => {
    renderForRoute(<Home router={router} />)
  },
  "user": () => {
    renderForRoute(<Slide router={router} />)
  }
};

DirectorRe.configure(router, {
  "html5history": true,
  "resources": handlers,
});

let renderForRoute = (element) => ReactDOMRe.renderToElementWithId(element, "root");


DirectorRe.init(router, "/");
/*

let renderForRoute = (route) =>
  ReactDOMRe.renderToElementWithId(<SlideShow route />, "root");

let router =
  DirectorRe.makeRouter({
    "/": () => renderForRoute(<Home />),
    "/slide/:id": (id: int) => renderForRoute(Routing.Slide(int_of_string(id)))
  });

DirectorRe.init(router, "/");
*/
