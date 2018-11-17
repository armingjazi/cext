
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

          steps {

            dir("build_debug") {
              echo 'Building Debug'
              sh 'cmake -D CMAKE_BUILD_TYPE=Debug ../'
            }

            dir("build_release") {
              echo 'Building Release'
              sh 'cmake CMAKE_BUILD_TYPE=Release ../'
            }
          }

        }

        stage('Linux Test') {
          steps {

              dir("build_release") {
                echo 'Testing Release'
                sh 'cd test && ./runAllTest'
              }
          }
        }

      }
    }
  }
}
