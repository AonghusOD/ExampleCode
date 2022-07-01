package com.example.exam1;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.List;

public class activityMain extends AppCompatActivity {
    public EditText number1, number2, number3, number4, number5;
    Button buttonMain;
    TextView t7, t8, t9, t10, t11, t12;
    double numb1, numb2, numb3, numb4, numb5;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        t7 = findViewById(R.id.textView7);
        t8 = findViewById(R.id.textView8);
        t9 = findViewById(R.id.textView9);
        t10 = findViewById(R.id.textView10);
        t11 = findViewById(R.id.textView11);
        t12 = findViewById(R.id.textView12);

        SharedPreferences myPrefs = getApplicationContext().getSharedPreferences("MyUserPrefs", Context.MODE_PRIVATE);
        String nu1= myPrefs.getString("num1", "");
        String nu2 = myPrefs.getString("num2", "");
        String nu3= myPrefs.getString("num3", "");
        String nu4 = myPrefs.getString("num4", "");
        String nu5= myPrefs.getString("num5", "");
        String Avg = myPrefs.getString("Average", "");
        t7.setText(nu1);
        t8.setText(nu2);
        t9.setText(nu3);
        t10.setText(nu4);
        t11.setText(nu5);
        t12.setText(Avg);

        number1 = (EditText) findViewById(R.id.number1);
        number2 = (EditText) findViewById(R.id.number2);
        number3 = (EditText) findViewById(R.id.number3);
        number4 = (EditText) findViewById(R.id.number4);
        number5 = (EditText) findViewById(R.id.number5);

        buttonMain = findViewById(R.id.buttonMain);

        buttonMain.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View View) {
                numb1 = Double.parseDouble(number1.getText().toString());
                numb2 = Double.parseDouble(number2.getText().toString());
                numb3 = Double.parseDouble(number3.getText().toString());
                numb4 = Double.parseDouble(number4.getText().toString());
                numb5 = Double.parseDouble(number5.getText().toString());


                // creating a bundle instance
                Bundle bundle = new Bundle();
                // passing the data into the bundle
                bundle.putString("Number1", numb1 + "");
                bundle.putString("Number2", numb2 + "");
                bundle.putString("Number3", numb3 + "");
                bundle.putString("Number4", numb4 + "");
                bundle.putString("Number5", numb5 + "");


                Intent intent = new Intent(activityMain.this, activityOne.class);
                // passing the bundle to the intent
                intent.putExtras(bundle);

                Toast.makeText(activityMain.this, "Info | Saved", Toast.LENGTH_LONG).show();

                // starting the activity by passing the intent
                // to it.
                startActivity(intent);
            }
        });
    }


}
