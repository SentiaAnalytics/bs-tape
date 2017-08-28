type t;

type testTool = {
  plan: (int => unit),
  ok: (bool => unit)
};

let test : string => (testTool => unit) => unit;