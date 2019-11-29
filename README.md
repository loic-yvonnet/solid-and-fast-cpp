# SOLID and FAST C++

This repo contains the code and slides of a presentation about SOLID and FAST C++.

Build instructions may be found at [docker-latest-gcc-cmake](https://github.com/loic-yvonnet/docker-latest-gcc-cmake).

FAST principles extend the SOLID principles. The SOLID principles were shaped around Object-Oriented Programming style. The SOLID principles are well-known and documented. In C++20, we can use concepts and compile-time polymorphism to immplement the SOLID principles.

The SOLID principles stand for:
* **S**ingle Responsibility: a class or function should have a single responsibility or be refactored.
* **O**pen/close: use polymorphism to get code that is open for extension and close for modifications.
* **L**iskov substitution: we should be able to substitute a derived class instance instead of base class instance.
* **I**nterface seggregation: an interface or concept should have a single responsibility or be refactored.
* **D**ependency inversion: dependencies should be exposed in constructors and rely on concepts instead of specific types.

The FAST principles stand for:
* **F**unctional-style: C++ is multi paradigm programming language, and many modern features were designed around algebraic structures (optional, variant, ranges, etc.).
* **A**lgorithms: use the STL algorithms and write code in terms of data structures and algorithms.
* **S**ecurity: follow standards and best practices to enforce security.
* **T**ests: use automated testing tools and techniques and use continuous integration, even in legacy C++ code bases.

The slides provide a quick presentation of FAST, which is not about speed, but software quality in C++.
