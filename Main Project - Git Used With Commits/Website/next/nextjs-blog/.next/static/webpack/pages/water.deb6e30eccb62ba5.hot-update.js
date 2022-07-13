"use strict";
/*
 * ATTENTION: An "eval-source-map" devtool has been used.
 * This devtool is neither made for production nor for readable output files.
 * It uses "eval()" calls to create a separate source file with attached SourceMaps in the browser devtools.
 * If you are trying to read the output file, select a different devtool (https://webpack.js.org/configuration/devtool/)
 * or disable the default devtool with "devtool: false".
 * If you are looking for production-ready output files, see mode: "production" (https://webpack.js.org/configuration/mode/).
 */
self["webpackHotUpdate_N_E"]("pages/water",{

/***/ "./components/water/getWaterItem.js":
/*!******************************************!*\
  !*** ./components/water/getWaterItem.js ***!
  \******************************************/
/***/ (function(module, __webpack_exports__, __webpack_require__) {

eval("__webpack_require__.r(__webpack_exports__);\n/* harmony import */ var react_jsx_dev_runtime__WEBPACK_IMPORTED_MODULE_0__ = __webpack_require__(/*! react/jsx-dev-runtime */ \"./node_modules/react/jsx-dev-runtime.js\");\n/* harmony import */ var react_jsx_dev_runtime__WEBPACK_IMPORTED_MODULE_0___default = /*#__PURE__*/__webpack_require__.n(react_jsx_dev_runtime__WEBPACK_IMPORTED_MODULE_0__);\n/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_1__ = __webpack_require__(/*! react */ \"./node_modules/react/index.js\");\n/* harmony import */ var react__WEBPACK_IMPORTED_MODULE_1___default = /*#__PURE__*/__webpack_require__.n(react__WEBPACK_IMPORTED_MODULE_1__);\n/* harmony import */ var chart_js_auto__WEBPACK_IMPORTED_MODULE_2__ = __webpack_require__(/*! chart.js/auto */ \"./node_modules/chart.js/auto/auto.esm.js\");\n/* harmony import */ var _getWaterData__WEBPACK_IMPORTED_MODULE_3__ = __webpack_require__(/*! ./getWaterData */ \"./components/water/getWaterData.js\");\n/* harmony import */ var _getData_list__WEBPACK_IMPORTED_MODULE_4__ = __webpack_require__(/*! ../getData-list */ \"./components/getData-list.js\");\n/* harmony import */ var bootstrap_dist_css_bootstrap_css__WEBPACK_IMPORTED_MODULE_5__ = __webpack_require__(/*! bootstrap/dist/css/bootstrap.css */ \"./node_modules/bootstrap/dist/css/bootstrap.css\");\n/* harmony import */ var bootstrap_dist_css_bootstrap_css__WEBPACK_IMPORTED_MODULE_5___default = /*#__PURE__*/__webpack_require__.n(bootstrap_dist_css_bootstrap_css__WEBPACK_IMPORTED_MODULE_5__);\n/* harmony import */ var react_bootstrap_table_next_dist_react_bootstrap_table2_min_css__WEBPACK_IMPORTED_MODULE_6__ = __webpack_require__(/*! react-bootstrap-table-next/dist/react-bootstrap-table2.min.css */ \"./node_modules/react-bootstrap-table-next/dist/react-bootstrap-table2.min.css\");\n/* harmony import */ var react_bootstrap_table_next_dist_react_bootstrap_table2_min_css__WEBPACK_IMPORTED_MODULE_6___default = /*#__PURE__*/__webpack_require__.n(react_bootstrap_table_next_dist_react_bootstrap_table2_min_css__WEBPACK_IMPORTED_MODULE_6__);\n/* harmony import */ var react_bootstrap_table_next__WEBPACK_IMPORTED_MODULE_7__ = __webpack_require__(/*! react-bootstrap-table-next */ \"./node_modules/react-bootstrap-table-next/lib/index.js\");\n\n\n\n\n\n\n\n\n\n\nvar columns = [\n    {\n        dataField: \"id\",\n        text: \"Sensor ID\",\n        sort: true\n    },\n    {\n        dataField: \"name\",\n        text: \"Product Name\",\n        sort: true\n    },\n    {\n        dataField: \"price\",\n        text: \"Product Price in $\"\n    }\n];\nfunction GetWaterItem(props) {\n    var items = props.items;\n    var products = [\n        {\n            id: \"PH\",\n            name: props.PH,\n            price: props.TIME\n        },\n        {\n            id: \"TDS\",\n            name: props.TDS,\n            price: props.TIME\n        }\n    ];\n    return /*#__PURE__*/ (0,react_jsx_dev_runtime__WEBPACK_IMPORTED_MODULE_0__.jsxDEV)(\"div\", {\n        className: \"App\",\n        children: /*#__PURE__*/ (0,react_jsx_dev_runtime__WEBPACK_IMPORTED_MODULE_0__.jsxDEV)(react_bootstrap_table_next__WEBPACK_IMPORTED_MODULE_7__[\"default\"], {\n            bootstrap4: true,\n            keyField: \"id\",\n            data: products,\n            columns: columns\n        }, void 0, false, {\n            fileName: \"C:\\\\fsd\\\\next\\\\next-blog\\\\components\\\\water\\\\getWaterItem.js\",\n            lineNumber: 37,\n            columnNumber: 7\n        }, this)\n    }, void 0, false, {\n        fileName: \"C:\\\\fsd\\\\next\\\\next-blog\\\\components\\\\water\\\\getWaterItem.js\",\n        lineNumber: 36,\n        columnNumber: 5\n    }, this);\n}\n_c = GetWaterItem;\n/* harmony default export */ __webpack_exports__[\"default\"] = (GetWaterItem);\nvar _c;\n$RefreshReg$(_c, \"GetWaterItem\");\n\n\n;\n    // Wrapped in an IIFE to avoid polluting the global scope\n    ;\n    (function () {\n        var _a, _b;\n        // Legacy CSS implementations will `eval` browser code in a Node.js context\n        // to extract CSS. For backwards compatibility, we need to check we're in a\n        // browser context before continuing.\n        if (typeof self !== 'undefined' &&\n            // AMP / No-JS mode does not inject these helpers:\n            '$RefreshHelpers$' in self) {\n            // @ts-ignore __webpack_module__ is global\n            var currentExports = module.exports;\n            // @ts-ignore __webpack_module__ is global\n            var prevExports = (_b = (_a = module.hot.data) === null || _a === void 0 ? void 0 : _a.prevExports) !== null && _b !== void 0 ? _b : null;\n            // This cannot happen in MainTemplate because the exports mismatch between\n            // templating and execution.\n            self.$RefreshHelpers$.registerExportsForReactRefresh(currentExports, module.id);\n            // A module can be accepted automatically based on its exports, e.g. when\n            // it is a Refresh Boundary.\n            if (self.$RefreshHelpers$.isReactRefreshBoundary(currentExports)) {\n                // Save the previous exports on update so we can compare the boundary\n                // signatures.\n                module.hot.dispose(function (data) {\n                    data.prevExports = currentExports;\n                });\n                // Unconditionally accept an update to this module, we'll check if it's\n                // still a Refresh Boundary later.\n                // @ts-ignore importMeta is replaced in the loader\n                module.hot.accept();\n                // This field is set when the previous version of this module was a\n                // Refresh Boundary, letting us know we need to check for invalidation or\n                // enqueue an update.\n                if (prevExports !== null) {\n                    // A boundary can become ineligible if its exports are incompatible\n                    // with the previous exports.\n                    //\n                    // For example, if you add/remove/change exports, we'll want to\n                    // re-execute the importing modules, and force those components to\n                    // re-render. Similarly, if you convert a class component to a\n                    // function, we want to invalidate the boundary.\n                    if (self.$RefreshHelpers$.shouldInvalidateReactRefreshBoundary(prevExports, currentExports)) {\n                        module.hot.invalidate();\n                    }\n                    else {\n                        self.$RefreshHelpers$.scheduleUpdate();\n                    }\n                }\n            }\n            else {\n                // Since we just executed the code for the module, it's possible that the\n                // new exports made it ineligible for being a boundary.\n                // We only care about the case when we were _previously_ a boundary,\n                // because we already accepted this update (accidental side effect).\n                var isNoLongerABoundary = prevExports !== null;\n                if (isNoLongerABoundary) {\n                    module.hot.invalidate();\n                }\n            }\n        }\n    })();\n//# sourceURL=[module]\n//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJmaWxlIjoiLi9jb21wb25lbnRzL3dhdGVyL2dldFdhdGVySXRlbS5qcy5qcyIsIm1hcHBpbmdzIjoiOzs7Ozs7Ozs7Ozs7O0FBQUE7QUFBbUQ7QUFDWjtBQUNMO0FBQ21CO0FBQ1g7QUFDQTtBQUNBO0FBQzhCO0FBQ2hCO0FBR3hELElBQU1XLE9BQU8sR0FBRztJQUNkO1FBQ0VDLFNBQVMsRUFBRSxJQUFJO1FBQ2ZDLElBQUksRUFBRSxXQUFXO1FBQ2pCQyxJQUFJLEVBQUUsSUFBSTtLQUNYO0lBQ0Q7UUFDRUYsU0FBUyxFQUFFLE1BQU07UUFDakJDLElBQUksRUFBRSxjQUFjO1FBQ3BCQyxJQUFJLEVBQUUsSUFBSTtLQUNYO0lBQ0Q7UUFDRUYsU0FBUyxFQUFFLE9BQU87UUFDbEJDLElBQUksRUFBRSxvQkFBb0I7S0FDM0I7Q0FDRjtBQUVELFNBQVNFLFlBQVksQ0FBQ0MsS0FBSyxFQUFFO0lBQzNCLElBQU0sS0FBTyxHQUFLQSxLQUFLLENBQWZDLEtBQUs7SUFDYixJQUFNQyxRQUFRLEdBQUc7UUFDZjtZQUFFQyxFQUFFLEVBQUUsSUFBSTtZQUFFQyxJQUFJLEVBQUVKLEtBQUssQ0FBQ0ssRUFBRTtZQUFFQyxLQUFLLEVBQUVOLEtBQUssQ0FBQ08sSUFBSTtTQUFFO1FBQy9DO1lBQUVKLEVBQUUsRUFBRSxLQUFLO1lBQUVDLElBQUksRUFBRUosS0FBSyxDQUFDUSxHQUFHO1lBQUVGLEtBQUssRUFBRU4sS0FBSyxDQUFDTyxJQUFJO1NBQUU7S0FDbEQ7SUFDRCxxQkFDRSw4REFBQ0UsS0FBRztRQUFDQyxTQUFTLEVBQUMsS0FBSztrQkFDbEIsNEVBQUNoQixrRUFBYztZQUNiaUIsVUFBVTtZQUNWQyxRQUFRLEVBQUMsSUFBSTtZQUNiQyxJQUFJLEVBQUVYLFFBQVE7WUFDZFAsT0FBTyxFQUFFQSxPQUFPOzs7OztnQkFDaEI7Ozs7O1lBQ0UsQ0FDTjtDQUNIO0FBaEJRSSxLQUFBQSxZQUFZO0FBaUJyQiwrREFBZUEsWUFBWSxFQUFDIiwic291cmNlcyI6WyJ3ZWJwYWNrOi8vX05fRS8uL2NvbXBvbmVudHMvd2F0ZXIvZ2V0V2F0ZXJJdGVtLmpzP2YzY2UiXSwic291cmNlc0NvbnRlbnQiOlsiaW1wb3J0IFJlYWN0LCB7IHVzZUVmZmVjdCwgdXNlU3RhdGUgfSBmcm9tIFwicmVhY3RcIjtcbmltcG9ydCB7IExpbmUgfSBmcm9tIFwicmVhY3QtY2hhcnRqcy0yXCI7XG5pbXBvcnQgQ2hhcnQgZnJvbSBcImNoYXJ0LmpzL2F1dG9cIjtcbmltcG9ydCB7IEdyaWQsIENhcmQsIFRleHQgfSBmcm9tIFwiQG5leHR1aS1vcmcvcmVhY3RcIjtcbmltcG9ydCBHZXRXYXRlckRhdGEgZnJvbSBcIi4vZ2V0V2F0ZXJEYXRhXCI7XG5pbXBvcnQgR2V0RGF0YUxpc3QgZnJvbSBcIi4uL2dldERhdGEtbGlzdFwiO1xuaW1wb3J0IFwiYm9vdHN0cmFwL2Rpc3QvY3NzL2Jvb3RzdHJhcC5jc3NcIjtcbmltcG9ydCBcInJlYWN0LWJvb3RzdHJhcC10YWJsZS1uZXh0L2Rpc3QvcmVhY3QtYm9vdHN0cmFwLXRhYmxlMi5taW4uY3NzXCI7XG5pbXBvcnQgQm9vdHN0cmFwVGFibGUgZnJvbSBcInJlYWN0LWJvb3RzdHJhcC10YWJsZS1uZXh0XCI7XG5cblxuY29uc3QgY29sdW1ucyA9IFtcbiAge1xuICAgIGRhdGFGaWVsZDogXCJpZFwiLFxuICAgIHRleHQ6IFwiU2Vuc29yIElEXCIsXG4gICAgc29ydDogdHJ1ZVxuICB9LFxuICB7XG4gICAgZGF0YUZpZWxkOiBcIm5hbWVcIixcbiAgICB0ZXh0OiBcIlByb2R1Y3QgTmFtZVwiLFxuICAgIHNvcnQ6IHRydWVcbiAgfSxcbiAge1xuICAgIGRhdGFGaWVsZDogXCJwcmljZVwiLFxuICAgIHRleHQ6IFwiUHJvZHVjdCBQcmljZSBpbiAkXCJcbiAgfVxuXTtcblxuZnVuY3Rpb24gR2V0V2F0ZXJJdGVtKHByb3BzKSB7XG4gIGNvbnN0IHsgaXRlbXMgfSA9IHByb3BzO1xuICBjb25zdCBwcm9kdWN0cyA9IFtcbiAgICB7IGlkOiBcIlBIXCIsIG5hbWU6IHByb3BzLlBILCBwcmljZTogcHJvcHMuVElNRSB9LFxuICAgIHsgaWQ6IFwiVERTXCIsIG5hbWU6IHByb3BzLlREUywgcHJpY2U6IHByb3BzLlRJTUUgfVxuICBdO1xuICByZXR1cm4gKFxuICAgIDxkaXYgY2xhc3NOYW1lPVwiQXBwXCI+XG4gICAgICA8Qm9vdHN0cmFwVGFibGVcbiAgICAgICAgYm9vdHN0cmFwNFxuICAgICAgICBrZXlGaWVsZD1cImlkXCJcbiAgICAgICAgZGF0YT17cHJvZHVjdHN9XG4gICAgICAgIGNvbHVtbnM9e2NvbHVtbnN9XG4gICAgICAvPlxuICAgIDwvZGl2PlxuICApO1xufVxuZXhwb3J0IGRlZmF1bHQgR2V0V2F0ZXJJdGVtOyJdLCJuYW1lcyI6WyJSZWFjdCIsInVzZUVmZmVjdCIsInVzZVN0YXRlIiwiTGluZSIsIkNoYXJ0IiwiR3JpZCIsIkNhcmQiLCJUZXh0IiwiR2V0V2F0ZXJEYXRhIiwiR2V0RGF0YUxpc3QiLCJCb290c3RyYXBUYWJsZSIsImNvbHVtbnMiLCJkYXRhRmllbGQiLCJ0ZXh0Iiwic29ydCIsIkdldFdhdGVySXRlbSIsInByb3BzIiwiaXRlbXMiLCJwcm9kdWN0cyIsImlkIiwibmFtZSIsIlBIIiwicHJpY2UiLCJUSU1FIiwiVERTIiwiZGl2IiwiY2xhc3NOYW1lIiwiYm9vdHN0cmFwNCIsImtleUZpZWxkIiwiZGF0YSJdLCJzb3VyY2VSb290IjoiIn0=\n//# sourceURL=webpack-internal:///./components/water/getWaterItem.js\n");

/***/ })

});