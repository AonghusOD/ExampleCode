import React from "react";
import classes from "./MainNavigation.module.css";
import { useContext } from "react";
import DataContext from "../store/data-store.js";
import { Avatar } from '@nextui-org/react';

function Counter(props) {
  const dataCtx = useContext(DataContext);
  let noOfEmployees = dataCtx.getNoEmployees();

  return (
    <div className={classes.linkDiv}>
      <Avatar
        text={noOfEmployees}
        size="sm"
        color="success"
        textColor="white"
      />
    </div>
  );
}

export default Counter;
