                                                                                                                                                                                  package com.example.applicationdemojni

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.util.Log
import android.widget.TextView
import com.example.applicationdemojni.databinding.ActivityMainBinding
import com.example.applicationdemojni.model.Person

                                                                                                                                                                                  class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = stringFromJNI()
        Log.e(TAG, "onCreate: sum2Integer(12,45) = ${sum2IntegerJNI(12,45)}" , )
        Log.e(TAG, "onCreate: stringFJ2C(transfer string j->c): ${stringFJ2C("transfer string j->c")} " , )
        var person = Person(age = 23, name = "TANA", id = "123")
        Log.e(TAG, "onCreate: personObjectFJ2C: ${personObjectFJ2C(person = person)}", )


    }

    /**
     * A native method that is implemented by the 'applicationdemojni' native library,
     * which is packaged with this application.
     */
    private external fun stringFromJNI(): String
    external fun sum2IntegerJNI(a: Int, b: Int): Long
    external fun stringFJ2C(message: String): String
    external fun personObjectFJ2C(person: Person): String

    companion object {
        final val TAG = "MAIN_ACTIVITY"
        // Used to load the 'applicationdemojni' library on application startup.
        init {
            System.loadLibrary("applicationdemojni")
        }
    }
}