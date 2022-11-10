foo->bar == +x +. 1.0
// ^ operator
//       ^ operator
//          ^ operator
//            ^ operator


{ .  "x": 1 }
//    ^ property

switch foo {
// <- conditional
| [1, x, ...rest] =>
//^ type
// ^ number
//    ^ parameter
//        ^ punctuation.special
//            ^ parameter
//                ^ punctuation.special
  42
| [1, 2, ...[ b, ..._ ] as rest] => rest
//                   ^ parameter
//                                ^ variable
| exception Js.Exn.Error(_) => 99
//^ exception
}

switch bar {
| #...Mod.t => 33
//^ constant
}

{ foo, bar: baz, qux: 1 }
//^ property
//     ^ property

exception InputClosed(string)
//<- exception

raise(InputClosed("The stream has closed!"))
//<- exception

try {
//<- exception
  someOtherJSFunctionThatThrows()
} catch {
// ^ exception
| Not_found => 1 // catch a reason exception
| Invalid_argument(_) => 2 // catch a second reason exception
| Js.Exn.Error(obj) => 3 // catch the JS exception
}


let c = [a, ...[b]]
//          ^ type
//           ^ variable
//                      ^ variable
