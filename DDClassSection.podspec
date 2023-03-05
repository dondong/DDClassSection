#
# Be sure to run `pod lib lint DDClassSection.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name     = 'DDClassSection'
  s.version  = '0.0.1'
  s.license  = 'MIT'
  s.summary  = 'A description of DDClassSection.'
  s.homepage = 'https://github.com/dondong/DDKit'
  s.authors  = { 'dondong' => 'the-last-choice@qq.com' }
  s.source   = { :git => 'https://github.com/dondong/DDClassSection.git', :tag => s.version }
  
  s.platform = :ios
  s.ios.deployment_target = '9.0'

  s.ios.pod_target_xcconfig = { 'PRODUCT_BUNDLE_IDENTIFIER' => 'com.dd.kit.class.section' }

  s.source_files = 'Framework/DDClassSection/DDClassSection.h'
  s.public_header_files = 'Framework/DDClassSection/DDClassSection.h'
  s.subspec 'Register' do |ss|
    ss.source_files = 'Framework/DDClassSection/Class/Register/*.{h,m}'
    ss.public_header_files = 'Framework/DDClassSection/Class/Register/*.h'
  end
  s.subspec 'Loader' do |ss|
    ss.source_files = 'Framework/DDClassSection/Class/Loader/*.{h,m}'
    ss.public_header_files = 'Framework/DDClassSection/Class/Loader/*.h'
    ss.subspec 'core' do |sss|
      sss.source_files = 'Framework/DDClassSection/Class/Loader/core/*.{h,c}'
      sss.public_header_files = 'Framework/DDClassSection/Class/Loader/core/*.h'
    end
  end

end
