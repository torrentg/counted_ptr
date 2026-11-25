# counted_ptr

A lightweight single-allocation reference-counted smart pointer for C++ with no weak references and minimal overhead.

Inspired by `std::shared_ptr`, but intentionally limited to the features required for lightweight shared ownership.

Features:

* `sizeof(counted_ptr<T>) = sizeof(void*)`.
* Behaves like a pointer to `T`.
* Shared ownership with a single-pointer representation.
* Stores the reference counter alongside the managed object.
* Shared ownership without a separate control block.
* Requires a single allocation.

Main drawbacks:

* `make_counted<T>()` is the only way to create the referenced object.
* Cannot be constructed from a raw pointer.
* No support for weak references.
* No custom deleters.

## Usage

Drop [`counted_ptr.hpp`](counted_ptr.hpp) into your project and start using `counted_ptr`.

```c++
#include "couted_ptr.hpp"
...
counted_ptr<user_t> user = make_counted<user_t>("jdoe", false);

if (user)
  std::printf("User: %s, is_admin: %d\n", user->name, (*user).is_admin);
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
