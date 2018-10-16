import * as path from 'path';
const addon = require(path.resolve(__dirname, './../build/Release/myModule'));

const invPoissonDistribution: (n: number, prob: number) => number = addon.invPoissonDistribution;
const poissonDistribution: (n: number, expValue: number) => number = addon.poissonDistribution;

export { invPoissonDistribution, poissonDistribution };