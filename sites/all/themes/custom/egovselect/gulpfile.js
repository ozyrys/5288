/*global -$ */
'use strict';
var gulp = require('gulp');
var $ = require('gulp-load-plugins')();
var sourcemaps = require('gulp-sourcemaps');
var sass = require('gulp-sass');
var autoprefixer = require('gulp-autoprefixer');
var cleanCSS = require('gulp-clean-css');
var minify = require('gulp-minify');
var concat = require('gulp-concat');
//for live reload use this extension https://chrome.google.com/webstore/detail/livereload/jnihajbhpnppcggbcgedagnkighmdlei?hl=en
var plugins = require('gulp-load-plugins')({
    rename: {
    'gulp-live-server': 'serve'
   }
});

// Error notifications
var reportError = function(error) {
  $.notify({
    title: 'Gulp Task Error',
    message: 'Check the console.'
  }).write(error);
  console.log(error.toString());
  this.emit('end');
}

/** 
 * Sass compiling
 * Options
 * Compile function
 */
 var autoprefixerOptions = {
  browsers: ['last 2 versions', '> 5%', 'Firefox ESR']
};


/**
 * JS Compiling
 * Add js libraries to compiled in the src array first
 * All js is compiled to 'all.js'.
 * EG ['./node_modules/slider/slider.js','./js/scripts.js']
 */
gulp.task('js', function () {
    gulp.src(['./assets/scripts/onepage.js'])
      .pipe($.beautify({indentSize: 2}))
      .pipe(concat('onepage.js'))
      .pipe(minify({ext: '.min.js'}))
      .pipe(gulp.dest('./assets/scripts'))
      .pipe($.notify({
      title: "JS Compiled",
      message: "JS has been recompiled",
      onLast: true
    }));
});



// Run drush to clear the theme registry
gulp.task('drush', function() {
  return gulp.src('', {
      read: false
    })
    .pipe($.shell([
      'drush cc all',
    ]))
    .pipe($.notify({
      title: "Caches cleared",
      message: "Drupal CSS/JS caches cleared.",
      onLast: true
    }));
});

gulp.task('default', ['js'], function() {
  plugins.livereload.listen();
  gulp.watch(['assets/scripts/onepage.js'], ['js']);
});