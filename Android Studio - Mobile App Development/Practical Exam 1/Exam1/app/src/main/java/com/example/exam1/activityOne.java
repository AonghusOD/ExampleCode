package com.example.exam1;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

public class activityOne extends AppCompatActivity {
    TextView viewNumb1, viewNumb2, viewNumb3, viewNumb4, viewNumb5, viewSum;
    SharedPreferences myPrefs;
    Button button2;
    String spNum1;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_one);


        viewNumb1 = findViewById(R.id.textView);
        viewNumb2 = findViewById(R.id.textView2);
        viewNumb3 = findViewById(R.id.textView3);
        viewNumb4 = findViewById(R.id.textView4);
        viewNumb5 = findViewById(R.id.textView5);
        viewSum = findViewById(R.id.textView6);

        // get the Intent that started this Activity
        Intent intent = getIntent();

        // getting the bundle from the intent
        Bundle bundle = intent.getExtras();

        String Number1 = bundle.getString("Number1");
        Double doub1 = Double.parseDouble(Number1);
        String Number2 = bundle.getString("Number2");
        Double doub2 = Double.parseDouble(Number2);
        String Number3 = bundle.getString("Number3");
        Double doub3 = Double.parseDouble(Number3);
        String Number4 = bundle.getString("Number4");
        Double doub4 = Double.parseDouble(Number4);
        String Number5 = bundle.getString("Number5");
        Double doub5 = Double.parseDouble(Number5);

        Double sum = (doub1 + doub2 + doub3 + doub4 + doub5)/5;


        String Average = Double.toString(sum);

        // setting the text in the textview
        viewNumb1.setText(bundle.getString("Number1"));
        viewNumb2.setText(bundle.getString("Number2"));
        viewNumb3.setText(bundle.getString("Number3"));
        viewNumb4.setText(bundle.getString("Number4"));
        viewNumb5.setText(bundle.getString("Number5"));
        viewSum.setText("Average " + Average);

        myPrefs = getSharedPreferences("MyUserPrefs", Context.MODE_PRIVATE);

//        button2.setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View View){
//                spNum1 = viewNumb1.getText().toString();
//
//                SharedPreferences.Editor editor = myPrefs.edit();
//
//                editor.putString("viewNumb1", spNum1);
////                editor.putString("num2", String.valueOf("number2"));
////                editor.putString("num3", String.valueOf("number3"));
////                editor.putString("num4", String.valueOf("number4"));
////                editor.putString("num5", String.valueOf("number5"));
//                //editor.putString("Average", Average);
//
//                editor.commit();
//
//                Toast.makeText(activityOne.this, "Info |Saved", Toast.LENGTH_LONG).show();
//            }
//        });

    }
}
