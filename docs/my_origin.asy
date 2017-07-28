path my_origin(pair pos, real scale = 1.)
{
  path res = shift(pos) * circle((0, 0), 1. * scale);

  path pA = arc((0, 0), 1. * scale, 0, 90);
  path resA = shift(pos) * buildcycle
    (pA, (0, 1. * scale)--(0, 0), (0, 0)--(1. * scale, 0));
  fill(resA, black);

  path pB = arc((0, 0), 1. * scale, 180, 270);
  path resB = shift(pos) * buildcycle
    (pB, (0, -1. * scale)--(0, 0), (0, 0) --(-1. * scale, 0));
  fill(resB, black);

  path t1 = shift(pos) * (1. * scale, 0)--(0, 0);

  return res ; // & resA & t1 & resB;
}

// from
// https:tex.stackexchange.com/questions/249659/how-to-center-a-label-inside-a-closed-path-in-asymptote
pair pathCG(path p, int numTestPoints = 50000)
{
  int numInside = 0;

  pair bl = min(p);
  pair tr = max(p);

  pair sumPair = (0,0);

  for (int i = 0; i < numTestPoints; ++i)
    {
      pair testPoint = (
                        unitrand() * (tr.x - bl.x) + bl.x,
                        unitrand() * (tr.y - bl.y) + bl.y
                        );

      if (inside(p, testPoint))
        {
          sumPair = sumPair + testPoint;
          ++numInside;
        }
    }

  pair CG = (0,0);
  if (numInside > 0) { CG = sumPair / numInside; }

  return CG;
}
