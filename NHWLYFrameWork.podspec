Pod::Spec.new do |s|
s.name             = "NHWLYFrameWork"
s.version          = "1.1.3"
s.summary          = "A marquee view used on iOS."
s.description      = <<-DESC
It is a marquee view used on iOS, which implement by Objective-C.
DESC
s.homepage         = "https://github.com/niuhongwei/NHWLYFrameWork"
# s.screenshots      = "www.example.com/screenshots_1", "www.example.com/screenshots_2"
s.license          = 'MIT'
s.author           = { "niuhongwei" => "1075758430@qq.com" }
s.source           = { :git => "https://github.com/niuhongwei/NHWLYFrameWork.git", :tag => s.version }
# s.social_media_url = 'https://twitter.com/NAME'

s.platform     = :ios
# s.ios.deployment_target = '5.0'
# s.osx.deployment_target = '10.7'
s.requires_arc = true

#s.source_files = 'NHWLYFrameWork/*'
# s.resources = 'Assets'

# s.ios.exclude_files = 'Classes/osx'
# s.osx.exclude_files = 'Classes/ios'
# s.public_header_files = 'Classes/**/*.h'
s.preserve_paths = 'LEDMSSDK.framework'
s.vendored_frameworks = 'LEDMSSDK.framework'
s.frameworks = 'Foundation'

end
