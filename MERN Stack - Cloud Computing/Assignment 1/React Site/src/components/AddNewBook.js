import { useRef } from 'react'
import React from 'react'
import Card from './Card';
import classes from './AddNewBook.module.css';

//newmeetupform
const  AddNewBook = (props) => {

  const titleInputRef = useRef();
  const imageInputRef = useRef();

    const submitHandler = (event) => {
        event.preventDefault(); 
        const enteredTitle = titleInputRef.current.value;
        const enteredImage = imageInputRef.current.value;
  
    const bookDetails = {
      title: enteredTitle,
      image: enteredImage,
    };

    props.newBook2(bookDetails);
  
  }
  return (
    <div align="center">
  <Card>
      <form className={classes.form} onSubmit={submitHandler}>
        <div className={classes.control}>
          <label htmlFor='title'>Book Title</label>
          <input type='text' required id='title' ref={titleInputRef} />
        </div>
        <div className={classes.control}>
          <label htmlFor='image'>Book Image</label>
          <input type='url' id='image' ref={imageInputRef} />
        </div>
        
        <div className={classes.actions}>
          <button>Add Book</button> 
        </div>
      </form>
  </Card>
  </div>);
}
export default AddNewBook;