import React from "react";
import { useContext } from "react";
import DataContext from "../store/data-store.js";
import { Button, Spacer } from "@nextui-org/react";

function Books() {
  const dataCtx = useContext(DataContext);
  let noEmployees = dataCtx.getNoEmployees();

  function incrementEmployees() {
    noEmployees = dataCtx.getNoEmployees();
    noEmployees = parseInt(noEmployees) + 1;
    dataCtx.setNoEmployees("" + noEmployees);
  }
  function decrementEmployees() {
    noEmployees = dataCtx.getNoEmployees();
    noEmployees = parseInt(noEmployees) - 1;
    dataCtx.setNoEmployees("" + noEmployees);
  }
//removed flat
  return (
    <section>
      <div>
        <h1>There are {noEmployees} books</h1>
        <div>
          <Button color="success" auto onClick={() => incrementEmployees()}>
            Add book
          </Button>
        </div>
        <Spacer y={0.5} />
        <div>
          <Button color="error" auto onClick={() => decrementEmployees()}>
            Del book
          </Button>
        </div>
      </div>
    </section>
  );
}

export default Books;
