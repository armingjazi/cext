
pipeline {
  agent any

  environment {
    VERSION_NUMBER = "${BUILD_NUMBER}"
  }

  options {
    disableConcurrentBuilds()
    buildDiscarder(logRotator(numToKeepStr: '10'))
  }

  stages {

    stage('Build') {

      parallel {

        stage('Build Linux') {

          agent {
            node {
              label 'Linux'
            }
          }

          steps {

            dir("build_debug") {
              echo 'Building Debug'
              sh '../cmake .'
            }

            dir("build_release") {
              echo 'Building Release'
              sh '../cmake .'
            }
          }
          
        }
      }
    }
  }
