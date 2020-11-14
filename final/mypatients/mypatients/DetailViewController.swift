//  Created by Pedro Lanzieri on 13/11/20.
//

import UIKit

class DetailViewController: UIViewController {

    @IBOutlet var textArea: UITextView!
    var information: String!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        loadDetails()
    }
    
    func loadDetails() {
        
        self.textArea.text = information
        
    }

    

}

