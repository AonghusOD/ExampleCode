import AddNewBook from './AddNewBook';
import { useHistory } from 'react-router-dom';
import React from 'react'

const NewMeetupPage = (props) =>{
  const history = useHistory();
  function addBookHandler(bookDetails)
  {
    fetch(
      'https://serene-vim-306712-default-rtdb.firebaseio.com/books.json',
      {
        method: 'POST',
        body: JSON.stringify(bookDetails),
        headers: 
        {
          'Content-Type': 'application/json'
        }
      }
    ).then(() => {
      history.replace('/');
    });
  }
  return (
    <section>
      <h1>Add New Book</h1>
      <AddNewBook newBook2={addBookHandler}/>
    </section>
  );
} 
  
  export default NewMeetupPage;