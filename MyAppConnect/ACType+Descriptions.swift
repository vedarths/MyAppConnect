//
//  ACType+Descriptions.swift
//  HelloSwiftAppConnect
//
//  Copyright (c) 2017 MobileIron. All rights reserved.
//
//  YOUR USE AND DISTRIBUTION OF THIS SOFTWARE IS SUBJECT TO THE SOFTWARE DEVELOPMENT KIT (SDK) AGREEMENT BETWEEN
//  YOU AND MOBILE IRON, INC. (“MI”).  USE OR DISTRIBUTION NOT IN STRICT ACCORDANCE WITH THE AGREEMENT IS PROHIBITED.
//

import AppConnect.ACTypes

extension ACAuthState: CustomStringConvertible {
    public var description: String {
        switch self {
        case .authorized:
            return "Authorized"
        case .unauthorized:
            return "Unauthorized"
        case .retired:
            return "Retired"
        default:
            return "Unknown"
        }
    }
}

extension ACManagedPolicy: CustomStringConvertible {
    public var description: String {
        switch self {
        case .managed:
            return "Managed"
        case .unmanaged:
            return "Unmanaged"
        default:
            return "Unknown"
        }
    }
}

extension ACSecureServicesAvailability: CustomStringConvertible {
    public var description: String {
        switch self {
        case .available:
            return "Available"
        case .unavailable:
            return "Unavailable"
        default:
            return "Unknown"
        }
    }
}

extension ACPasteboardPolicy: CustomStringConvertible {
    public var description: String {
        switch self {
        case .authorized:
            return "Authorized"
        case .unauthorized:
            return "Unauthorized"
        case .secureCopy:
            return "Secure Copy (AppConnect Apps)"
        default:
            return "Unknown"
        }
    }
}

extension ACOpenInPolicy: CustomStringConvertible {
    public var description: String {
        switch self {
        case .authorized:
            return "Authorized for all apps"
        case .unauthorized:
            return "Unauthorized"
        case .whitelist:
            return "Authorized for whitelist"
        default:
            return "Unknown"
        }
    }
}

extension ACPrintPolicy: CustomStringConvertible {
    public var description: String {
        switch self {
        case .authorized:
            return "Authorized"
        case .unauthorized:
            return "Unauthorized"
        default:
            return "Unknown"
        }
    }
}

extension ACSecureFileIOPolicy: CustomStringConvertible {
    public var description: String {
        switch self {
        case .optional:
            return "Optional"
        case .required:
            return "Required"
        default:
            return "Unknown"
        }
    }
}

extension ACLogLevel: CustomStringConvertible {
    public var description: String {
        switch self {
        case .status:
            return "Status"
        case .warning:
            return "Warning"
        case .error:
            return "Error"
        case .info:
            return "Info"
        case .verbose:
            return "Verbose"
        case .debug:
            return "Debug"
        default:
            return "Unknown"
        }
    }
}
