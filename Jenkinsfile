
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

      stages {

        stage('Configure Linux') {

          steps {

            dir("build_debug") {
              echo 'Configuring Debug'
              sh 'cmake -D CMAKE_BUILD_TYPE=Debug ../'
            }

            dir("build_release") {
              echo 'Configuring Release'
              sh 'cmake CMAKE_BUILD_TYPE=Release ../'
            }
          }

        }

        stage('Build Linux') {

          steps {

            dir("build_debug") {
              echo 'Building Debug'
              sh 'make'
            }

            dir("build_release") {
              echo 'Building Release'
              sh '''
                  cmake -D CMAKE_BUILD_TYPE=Release -D -D CMAKE_INSTALL_PREFIX:PATH=local ..
                  make
              '''
            }
          }

        }

        stage('Linux Test') {
          steps {

              dir("build_release") {
                echo 'Testing Release'
                sh 'cd test && ./runALLTests --gtest_filter=UnitTest* --path=./test --gtest_output=xml:reports/'
                junit 'test/reports/*.xml'
              }
          }
        }

        stage('Package') {
          steps {
            dir("build_release") {
              archiveArtifacts artifacts: 'local/**', fingerprint: true, onlyIfSuccessful: true
            }
          }
        }
        
      }
    }
  }
}
