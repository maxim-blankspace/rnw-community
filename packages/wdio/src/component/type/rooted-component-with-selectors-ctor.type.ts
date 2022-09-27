import type { ComponentInputArg } from './component-input-arg.type';
import type { RootedComponentWithSelectors } from './rooted-component-with-selectors.type';

export type RootedComponentWithSelectorsCtor<T extends string, A = unknown> = new (
    selectorOrElement?: ComponentInputArg
) => A & RootedComponentWithSelectors<T>;
