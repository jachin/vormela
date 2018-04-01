#!/usr/bin/env python3

import os
import codecs
import markdown
from bs4 import BeautifulSoup
from string import Template

slides_dir = os.path.join(
    os.path.dirname(os.path.realpath(__file__)),
    'slides'
)
reasonReactJsx = []
for root, dirs, files in os.walk(slides_dir):
    for file_name in sorted(files):
        file_path = os.path.join(slides_dir, file_name)
        input_file = codecs.open(file_path, mode="r", encoding="utf-8")
        text = input_file.read()
        html = '<div className="slide">' + markdown.markdown(text) + "</div>"
        soup = BeautifulSoup(html, 'html.parser')

        for tag in soup.findAll():
            if tag.string is None:
                continue
            if len(tag.string) > 0:
                tag.string = '(str("' + tag.string.replace('"', '\\"') + '"))'

        reasonHtml = str(soup)
        reasonHtml = reasonHtml.replace('classname', 'className')
        reasonReactJsx.append(reasonHtml)

s = Template("""let str = ReasonReact.stringToElement;

let mySlideDeck = [|
  $slides
|];
""")

output = s.substitute(slides=',\n'.join(reasonReactJsx))

slides_path = os.path.join(
    os.path.dirname(os.path.realpath(__file__)),
    'src',
    'Slides.re'
)

with open(slides_path, 'w') as the_file:
    the_file.write(output)
