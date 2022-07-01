package com.example.exam1;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    public EditText number1, number2, number3, number4, number5;
    Button buttonMain;
    double numb1, numb2, numb3, numb4, numb5;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        number1 = (EditText) findViewById(R.id.number1);
        number2 = (EditText) findViewById(R.id.number2);
        number3 = (EditText) findViewById(R.id.number3);
        number4 = (EditText) findViewById(R.id.number4);
        number5 = (EditText) findViewById(R.id.number5);

        buttonMain = findViewById(R.id.buttonMain);

        buttonMain.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View View) {
                getDataFromForm();

                // creating a bundle instance
                Bundle bundle = new Bundle();
                // passing the data into the bundle
                bundle.putDouble("Number1", numb1);
                bundle.putDouble("Number2", numb2);
                bundle.putDouble("Number3", numb3);
                bundle.putDouble("Number4", numb4);
                bundle.putDouble("Number5", numb5);

                Intent intent = new Intent(MainActivity.this, activityOne.class);
                // passing the bundle to the intent
                intent.putExtras(bundle);
                Toast.makeText(MainActivity.this, "Info | Saved", Toast.LENGTH_LONG).show();

                // starting the activity by passing the intent
                // to it.
                startActivity(intent);
            }
        });
    }
    public void getDataFromForm() {
        numb1 = Double.parseDouble(number1.getText().toString());
        numb2 = Double.parseDouble(number2.getText().toString());
        numb3 = Double.parseDouble(number3.getText().toString());
        numb4 = Double.parseDouble(number1.getText().toString());
        numb5 = Double.parseDouble(number2.getText().toString());
    }

}
