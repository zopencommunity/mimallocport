node('linux')
{
  stage ('Poll') {
    checkout([
      $class: 'GitSCM',
      branches: [[name: '*/main']],
      doGenerateSubmoduleConfigurations: false,
      extensions: [],
      userRemoteConfigs: [[url: 'https://github.com/zopencommunity/mimallocport.git']]])
  }
  stage('Build') {
    build job: 'Port-Pipeline', parameters: [string(name: 'PORT_GITHUB_REPO', value: 'https://github.com/zopencommunity/mimallocport.git'), string(name: 'PORT_DESCRIPTION', value: 'mimalloc is a compact general purpose allocator with excellent performance.' ), string(name: 'BUILD_LINE', value: 'STABLE') ]
  }
}
