import React from 'react'
import { Grid, Card, Spacer, Text } from "@nextui-org/react";
import { Container, Row, Col } from '@nextui-org/react';
function LikesPage(props) 
{
  const { title, image, date, location, id, description } = props;
  const MockItem = ({ text }) => {
    return (
      <Card color="primary" css={{ h: "$24" }}>
        <Text h6 size={15} color="white" css={{ mt: 0 }}>
          {text}
        </Text>
      </Card>
    );
  };
  return (
    <Grid.Container gap={2} justify="center">
      <Grid xs={4}>
      <img src={image} alt={title} />
      </Grid>
      <Grid xs={4}>
        <MockItem text="2 of 3" />
      </Grid>
      <Grid xs={4}>
        <MockItem text="3 of 3" />
      </Grid>
    </Grid.Container>
  );
}
  export default LikesPage;