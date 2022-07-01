import { Table, Row, Col, Tooltip, User, Text } from "@nextui-org/react";
import { StyledBadge } from "./StyledBadge";
import { IconButton } from "./IconButton";
import { DeleteIcon } from "./DeleteIcon";
import { useContext } from "react";
import DataContext from "../../store/data-store";
import { useState, useRef, useEffect} from "react";


export default function CartItem(props) {
  const dataCtx = useContext(DataContext);
  let noEmployees = dataCtx.getNoEmployees();

  function decrementEmployees() {
    noEmployees = dataCtx.getNoEmployees();
    noEmployees = parseInt(noEmployees) - 1;
    dataCtx.setNoEmployees("" + noEmployees);
  }


  async function deleteCartItem({title})  {
    const response = await fetch('api/deleteCart', {
      method: 'DELETE',
      body: JSON.stringify({title}),
      headers: {
      'Content-Type': 'application/json'
      },
      
  });
  }

    const {title, id} = props;
    return (
      <Table
        bordered
        shadow={false}
        selectionMode="single"
        aria-label="Example static bordered collection table"
        css={{
          height: "auto",
          minWidth: "100%",
        }}
      >
        <Table.Header>
          <Table.Column>NAME</Table.Column>
          <Table.Column align="right">Add To Cart</Table.Column>
        </Table.Header>
        <Table.Body>
          <Table.Row key={id}>
            <Table.Cell>{title}</Table.Cell>
            <Table.Cell><IconButton onClick={() => {decrementEmployees();deleteCartItem({title});}}>
                  <DeleteIcon size={20} fill="#FF0080" />
                </IconButton></Table.Cell>
          </Table.Row>
        </Table.Body>
      </Table>
    );
  }