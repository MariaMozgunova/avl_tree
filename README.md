<div id="top"></div>



<!-- PROJECT SHIELDS -->
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li>
      <a href="#example">Example</a>
    </li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

This project is the AVL tree implementation functioning as a set. Inputs data from `avlset.in` file. Outputs result in `avlset.out` file. 
The format of the input is as follows:
- `N` (number of operations) goes on the first line
- Then `N` lines follow in the format `X x`
Where `X` could be:
- `A` - insert element into the set if it is not there
- `D` - delete the element from the set if it is there
- `C` - check the existence of an element in the set

`x` is of type `int`

The format of the output is as follows:
- for each request `C x`, outputs `Y` (element is in the set) or `N` (element is not in the set)
- outputs the balance of the root for each operation `A x` and `D x`

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

To see the set in action on your machine, follow the simple steps below.

### Installation

1. Clone the repo `git clone https://github.com/MariaMozgunova/avl_tree.git`
2. Create `avtset.in` and `avlset.out` files in the same directory
3. Run file `avl_tree.cpp`

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- EXAMPLE -->
## Example

Example of the input file:
```
6
A 3
A 4
A 5
C 4
C 6
D 5
```

Example of the corresponding output file:
```
0
1
0
Y
N
-1
```

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Maria Mozgunova - [Twitter - @MariaMozgunova](https://twitter.com/MariaMozgunova) - mariiamozgunova@gmail.com

Project Link: [https://github.com/MariaMozgunova/avl_tree](https://github.com/MariaMozgunova/avl_tree)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [README Template](https://github.com/othneildrew/Best-README-Template)

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[license-shield]: https://img.shields.io/github/license/othneildrew/Best-README-Template.svg?style=for-the-badge
[license-url]: https://github.com/MariaMozgunova/avl_tree/blob/master/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/mariamozgunova/
