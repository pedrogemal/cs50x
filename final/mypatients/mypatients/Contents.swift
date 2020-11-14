//  Created by Pedro Lanzieri on 13/11/20.
//

import Foundation

struct ContentList: Codable {
    let identifier: String
    let topics: [Topic]
}

struct Topic: Codable {
    let id: Int
    let title: String
    let text: String
}


