The-Nature-of-Code-Examples
===========================

Repository for example code from The Nature of Code book (http://natureofcode.com/)

The repo for book's raw content (text, illustrations, images, CSS, etc.): https://github.com/shiffman/The-Nature-of-Code

###Cinder Examples

The code samples for cinder vary in some very specific ways from processing due to differences in how some functions work, how some functions are named and the absence of some features. 

This is a list of some of the processing/cinder differences that you may encounter

* The ``PVector`` equivalent is ``Vec2f``
* Processing's ``map`` equivalent is ``lmap`` in cinder
* The equivalent ``noise`` function in cinder is ``Perlin::fBm()``
* Instead of arrays, C++ vectors and/or lists are used
* Cinder includes helper functions to draw out shapes using OpenGl such as ``drawSolidRect()``, ``drawSolidEllipse()``, etc. instead if ``rect()``, ``ellipse()``, etc.
* Instead of the setup function, some of the app specific settings are done in the ``prepareSettings()`` function, while variables are initialized in the ``setup`` function.
* Cinder has an ``update()`` function in addition to the draw function. Generally, ``update`` is used for updating values and doing calculations, while draw is for rendering out the visuals. That convention wasn't strictly adhered to, but has been implemented in select places.

You'll also notice that the variables are slightly different to conform with best practices within the Cinder/C++ coding environment. For instance, member variables often start with the letter 'm'. So instead of calling your variables 'x' and 'y', we often call them 'mX' and 'mY'. This is consistent to how the Cinder framework has been developed. 

Spacing conventions have been followed as much as possible as well. So instead of something like ``function(param1, param2);``, you'll see ``function( param1, param2 );``.

If you're new to C++, you may be thrown off my some member variables with * in front of it, such as *walker in many of the introduction examples. This refers to the variable being a pointer. You can read more about pointers [here](http://www.cplusplus.com/doc/tutorial/pointers/).