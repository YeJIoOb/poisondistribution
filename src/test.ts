import { invPoissonDistribution, poissonDistribution } from './index';

console.log(1/poissonDistribution(2, 0.5));

// function voidO(a: number) { }

// let i = 0;
// let sum = 0;
// console.time('invPoissonDistribution');
// while (i < 1000000) {
//   const res = invPoissonDistribution(0, 0.589744);
//   sum += res;
//   voidO(res);
//   i++;
// }
// console.log(sum / 1000000)
// console.timeEnd('invPoissonDistribution');
