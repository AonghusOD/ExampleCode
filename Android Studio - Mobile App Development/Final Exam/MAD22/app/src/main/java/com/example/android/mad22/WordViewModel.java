package com.example.android.mad22;

/*
 * Copyright (C) 2018 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

import android.app.Application;
import android.arch.lifecycle.AndroidViewModel;
import android.arch.lifecycle.LiveData;

import java.util.List;

/**
 * View Model to keep a reference to the word repository and
 * an up-to-date list of all words.
 */

public class WordViewModel extends AndroidViewModel {

    private com.example.android.mad22.WordRepository mRepository;
    // Using LiveData and caching what getAlphabetizedWords returns has several benefits:
    // - We can put an observer on the data (instead of polling for changes) and only update the
    //   the UI when the data actually changes.
    // - Repository is completely separated from the UI through the ViewModel.
    private LiveData<List<com.example.android.mad22.Word>> mAllWords;

    public WordViewModel (Application application) {
        super(application);
        mRepository = new com.example.android.mad22.WordRepository(application);
        mAllWords = mRepository.getAllWords();
    }

    LiveData<List<com.example.android.mad22.Word>> getAllWords() { return mAllWords; }

    public void insert(com.example.android.mad22.Word word) { mRepository.insert(word); }
}