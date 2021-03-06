Pod::Spec.new do |s|

  s.name         = "SwiftMatrixSDK"
  s.version      = "0.9.1"
  s.summary      = "The iOS SDK to build apps compatible with Matrix (https://www.matrix.org)"

  s.description  = <<-DESC
				   Matrix is a new open standard for interoperable Instant Messaging and VoIP, providing pragmatic HTTP APIs and open source reference implementations for creating and running your own real-time communication infrastructure.

				   Our hope is to make VoIP/IM as universal and interoperable as email.
                   DESC

  s.homepage     = "https://www.matrix.org"

  s.license      = { :type => "Apache License, Version 2.0", :file => "LICENSE" }

  s.author             = { "matrix.org" => "support@matrix.org" }
  s.social_media_url   = "http://twitter.com/matrixdotorg"

  s.ios.deployment_target = "8.0"
  s.osx.deployment_target = "10.10"

  s.source       = { :git => "https://github.com/matrix-org/matrix-ios-sdk.git", :tag => "v0.9.1" }
  s.source_files = "MatrixSDK", "MatrixSDK/**/*.{h,m,swift}"
  s.exclude_files   = "MatrixSDK/**/MXGoogleAnalytics.{h,m}"
  s.resources    = "MatrixSDK/Data/Store/MXCoreDataStore/*.xcdatamodeld"

  s.frameworks   = "CoreData"

  s.requires_arc  = true

  s.dependency 'AFNetworking', '~> 3.1.0'
  s.dependency 'GZIP', '~> 1.1.1'

end
