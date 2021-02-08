import { contextBridge } from "electron";
import { add } from "native-module";

console.log(add(5, 6));

const exposedApi = {
  add,
};

contextBridge.exposeInMainWorld("api", exposedApi);
