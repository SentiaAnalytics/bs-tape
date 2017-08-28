type t;

external _test : string => (t => unit) => unit = "test" [@@bs.module "tape"];
external _plan : t => int => unit = "plan" [@@bs.send];
external _ok : t => bool => unit = "ok" [@@bs.send];

type testTool = {
  plan: (int => unit),
  ok: (bool => unit)
};

let test name f => 
  _test name (fun t => {
    let tool = {
      plan: _plan t, 
      ok: _ok t 
    };
    f tool;
  });

