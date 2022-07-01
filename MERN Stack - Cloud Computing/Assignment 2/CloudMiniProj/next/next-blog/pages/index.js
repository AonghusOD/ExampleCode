import React from 'react'
import { Grid, Card, Spacer, Text } from "@nextui-org/react";
import { Container, Row, Col } from '@nextui-org/react';

import Head from 'next/head'

export default function Home() {
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
    <>
      <Head>
        <title>Home</title>
      </Head>
      <Grid.Container gap={2} justify="right">
      <Grid xs={2}>
      <img height="200px" src="https://m.media-amazon.com/images/P/B09KZNFNT1.01._SCLZZZZZZZ_SX500_.jpg" alt="title" />
      </Grid>
      <Grid xs={2}>
      <img height="200px" src="https://m.media-amazon.com/images/P/1847941834.01._SCLZZZZZZZ_SX500_.jpg" alt="title" />
      </Grid>
      <Grid xs={2}>
      <img height="200px" src="https://m.media-amazon.com/images/P/B08JCVMBZG.01._SCLZZZZZZZ_SX500_.jpg" alt="title" />
      </Grid>
      <Grid xs={2}>
      <img height="200px" src="https://images-na.ssl-images-amazon.com/images/I/61IsSmcySgL._SX358_BO1,204,203,200_.jpg" alt="title" />
      </Grid>
      <Grid xs={2}>
      <img height="200px" src="https://m.media-amazon.com/images/P/1501110365.01._SCLZZZZZZZ_SX500_.jpg" alt="title" />
      </Grid>
      <Grid xs={2}>
      <img height="200px" src="https://images-na.ssl-images-amazon.com/images/I/51+49bNtpAL._SX353_BO1,204,203,200_.jpg" alt="title" />
      </Grid>
      <Grid xs={2}>
      <img height="200px" src="https://images-na.ssl-images-amazon.com/images/I/51VWDP3YDNL._SX326_BO1,204,203,200_.jpg" alt="title" />
      </Grid>
      <Grid xs={2}>
      <img height="200px" src="https://m.media-amazon.com/images/P/1612434908.01._SCLZZZZZZZ_SX500_.jpg" alt="title" />
      </Grid>
      <Grid xs={2}>
      <img height="200px" src="https://images-na.ssl-images-amazon.com/images/I/41m1dn9l43L._SX370_BO1,204,203,200_.jpg" alt="title" />
      </Grid>
      <Grid xs={2}>
      <img height="200px" src="https://m.media-amazon.com/images/P/0471484849.01._SCLZZZZZZZ_SX500_.jpg" alt="title" />
      </Grid>
      <Grid xs={2}>
      <img height="200px" src="https://m.media-amazon.com/images/P/1483930076.01._SCLZZZZZZZ_SX500_.jpg" alt="title" />
      </Grid>
      <Grid xs={2}>
      <img height="200px" src="https://m.media-amazon.com/images/P/B00AHEMZAW.01._SCLZZZZZZZ_SX500_.jpg" alt="title" />
      </Grid>
      <Grid xs={2}>
      <img height="200px" src="https://images-na.ssl-images-amazon.com/images/I/51yJOsfLLWL._SX327_BO1,204,203,200_.jpg" alt="title" />
      </Grid>
      <Grid xs={2}>
      <img height="200px" src="https://m.media-amazon.com/images/P/1783289554.01._SCLZZZZZZZ_SX500_.jpg" alt="title" />
      </Grid>
      <Grid xs={2}>
      <img height="200px" src="https://m.media-amazon.com/images/P/0471776572.01._SCLZZZZZZZ_SX500_.jpg" alt="title" />
      </Grid>
      <Grid xs={2}>
      <img height="200px" src="https://images-na.ssl-images-amazon.com/images/I/41ywNyOJ6-L._SX327_BO1,204,203,200_.jpg" alt="title" />
      </Grid>
      <Grid xs={2}>
      <img height="200px" src="https://m.media-amazon.com/images/P/013427671X.01._SCLZZZZZZZ_SX500_.jpg" alt="title" />
      </Grid>
      <Grid xs={2}>
      <img height="200px" src="https://images-na.ssl-images-amazon.com/images/I/51fqXWLkqCL._SX371_BO1,204,203,200_.jpg" alt="title" />
      </Grid>
      
    </Grid.Container>
    </>
  );
}
