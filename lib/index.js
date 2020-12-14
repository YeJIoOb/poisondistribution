"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.poissonDistribution = exports.invPoissonDistribution = void 0;
const path = require("path");
const addon = require(path.resolve(__dirname, './../build/Release/myModule'));
const invPoissonDistribution = addon.invPoissonDistribution;
exports.invPoissonDistribution = invPoissonDistribution;
const poissonDistribution = addon.poissonDistribution;
exports.poissonDistribution = poissonDistribution;
