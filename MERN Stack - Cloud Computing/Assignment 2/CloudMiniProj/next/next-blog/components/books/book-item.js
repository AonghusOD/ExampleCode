import React from "react";
import { Modal, useModal, Text } from "@nextui-org/react";
import Button from '../ui/button';
import DateIcon from "../icons/date-icon";
import ArrowRightIcon from "../icons/arrow-right-icon";
import classes from "./book-item.module.css";
import { useContext } from "react";
import DataContext from "../../store/data-store";

function BookItem(props) {
  const dataCtx = useContext(DataContext);
  let noEmployees = dataCtx.getNoEmployees();

  function incrementEmployees() {
    noEmployees = dataCtx.getNoEmployees();
    noEmployees = parseInt(noEmployees) + 1;
    dataCtx.setNoEmployees("" + noEmployees);
  }

    async function setCart({title})  {
      const response = await fetch('api/setCart', {
        method: 'POST',
        body: JSON.stringify({title}),
        headers: {
        'Content-Type': 'application/json'
        },
        
    });
}
  const { title, image, date, location, id, description } = props;
  const { setVisible, bindings } = useModal();

  const humanReadableDate = new Date(date).toLocaleDateString("en-US", {
    day: "numeric",
    month: "long",
    year: "numeric",
  });
  return (
    <li className={classes.item}>
      <img src={image} alt={title} />
      <div className={classes.content}>
        <div className={classes.summary}>
          <h2 style={{ color: "red" }}>{title}</h2>
          <div className={classes.date}>
            <p style={{ color: "black" }}>Publish Date:</p>
            <DateIcon />
            <time>{humanReadableDate}</time>
          </div>
          <div className={classes.address}></div>
        </div>
        <br></br>
        <div>
          <Button
            auto
            shadow
            color="secondary"
            onClick={() => setVisible(true)}
          >
            Info
          </Button>
          &nbsp;&nbsp;&nbsp;&nbsp;
          <Modal
            scroll
            width="500px"
            aria-labelledby="modal-title"
            aria-describedby="modal-description"
            {...bindings}
          >
            <Modal.Header>
              <Text id="modal-title" size={18}>
                {title}
              </Text>
            </Modal.Header>
            <Modal.Body>
              <Text id="modal-description">{description}</Text>
            </Modal.Body>
            <Modal.Footer>
              <Button auto flat color="error" onClick={() => setVisible(false)}>
                Close
              </Button>
            </Modal.Footer>
          </Modal>
          
          <Button color="success" auto onClick={() => {incrementEmployees();setCart({title});}}>
            <span>Add To Basket</span>
            <span className={classes.icon}>
              <ArrowRightIcon />
            </span>
          </Button>
        </div>
        <div className={classes.actions}>
         
        </div>
      </div>
    </li>
  );
}

export default BookItem;
